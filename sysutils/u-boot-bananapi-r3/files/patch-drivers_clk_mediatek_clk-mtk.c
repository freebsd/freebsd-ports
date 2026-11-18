Fix using MediaTek clocks before relocation; without it the MT7986 UART
has no clock and U-Boot resets in a loop. Upstream, in 2027.01:
https://git.u-boot-project.org/u-boot/u-boot/-/commit/3ffad26f17cbe32df9b37f407b8984adecd97c0c

--- drivers/clk/mediatek/clk-mtk.c.orig	2026-10-05 21:35:33 UTC
+++ drivers/clk/mediatek/clk-mtk.c
@@ -35,8 +35,6 @@
 #define SCP_AXICK_DCM_DIS_EN		BIT(0)
 #define SCP_AXICK_26M_SEL_EN		BIT(4)
 
-static struct udevice *mtk_clk_providers[MTK_CLK_TREE_NUM_TYPES];
-
 static bool mtk_clk_tree_type_is_provider(enum mtk_clk_tree_type type)
 {
 	return type != MTK_CLK_TREE_NONE && type < MTK_CLK_TREE_NUM_TYPES;
@@ -58,44 +56,40 @@ static struct udevice *mtk_clk_tree_get_provider(enum 
 
 static struct udevice *mtk_clk_tree_get_provider(enum mtk_clk_tree_type type)
 {
+	struct udevice *dev;
+	struct uclass *uc;
+	int ret;
+
 	if (!mtk_clk_tree_type_is_provider(type))
 		return NULL;
 
-	if (!mtk_clk_providers[type]) {
-		struct udevice *dev;
-		struct uclass *uc;
-		int ret;
+	ret = uclass_get(UCLASS_CLK, &uc);
+	if (ret)
+		return ERR_PTR(ret);
 
-		/* Lazily probe and register the requested provider. */
-		ret = uclass_get(UCLASS_CLK, &uc);
-		if (ret)
-			return ERR_PTR(ret);
+	uclass_foreach_dev(dev, uc) {
+		const struct mtk_clk_tree *tree;
+		const void *ops;
 
-		uclass_foreach_dev(dev, uc) {
-			const struct mtk_clk_tree *tree;
-			const void *ops;
+		ops = dev_get_driver_ops(dev);
+		if (ops != &mtk_clk_apmixedsys_ops &&
+		    ops != &mtk_clk_fixed_pll_ops &&
+		    ops != &mtk_clk_topckgen_ops &&
+		    ops != &mtk_clk_infrasys_ops)
+			continue;
 
-			ops = dev_get_driver_ops(dev);
-			if (ops != &mtk_clk_apmixedsys_ops &&
-			    ops != &mtk_clk_fixed_pll_ops &&
-			    ops != &mtk_clk_topckgen_ops &&
-			    ops != &mtk_clk_infrasys_ops)
-				continue;
+		tree = (const void *)dev_get_driver_data(dev);
+		if (tree->type != type)
+			continue;
 
-			tree = (const void *)dev_get_driver_data(dev);
-			if (tree->type != type)
-				continue;
+		ret = device_probe(dev);
+		if (ret)
+			return ERR_PTR(ret);
 
-			/* Probe will add it to mtk_clk_providers[type]. */
-			ret = device_probe(dev);
-			if (ret)
-				return ERR_PTR(ret);
-
-			break;
-		}
+		return dev;
 	}
 
-	return mtk_clk_providers[type] ?: ERR_PTR(-ENOENT);
+	return ERR_PTR(-ENOENT);
 }
 
 static struct udevice *mtk_clk_parent_get_provider(u16 flags)
@@ -103,20 +97,6 @@ static struct udevice *mtk_clk_parent_get_provider(u16
 	return mtk_clk_tree_get_provider(mtk_clk_tree_type_from_parent_flags(flags));
 }
 
-static int mtk_clk_tree_register_provider(struct udevice *dev,
-					  const struct mtk_clk_tree *tree)
-{
-	if (!mtk_clk_tree_type_is_provider(tree->type))
-		return 0;
-
-	if (mtk_clk_providers[tree->type])
-		return -EEXIST;
-
-	mtk_clk_providers[tree->type] = dev;
-
-	return 0;
-}
-
 /* shared functions */
 
 static const int mtk_common_clk_of_xlate(struct clk *clk,
@@ -1128,5 +1108,5 @@ int mtk_clk_probe(struct udevice *dev)
 
 	priv->tree = tree;
 
-	return mtk_clk_tree_register_provider(dev, tree);
+	return 0;
 }
