--- math++/nodes.tcc.orig	Fri Aug 13 13:01:46 2004
+++ math++/nodes.tcc	Fri Aug 13 13:10:49 2004
@@ -92,7 +92,7 @@
 // TNumberNode
 template<typename T>
 TNumberNode<T>::TNumberNode(const T& ANumber) :
-    TNode<T>(NUMBER_NODE, 0), FNumber(ANumber) {
+    TNode<T>(TNode<T>::NUMBER_NODE, 0), FNumber(ANumber) {
 }
 
 template<typename T>
@@ -112,14 +112,14 @@
 
 template<typename T>
 bool TNumberNode<T>::equals(const TNode<T> *ANode) const {
-    return this && ANode && ANode->nodeType() == NUMBER_NODE
+    return this && ANode && ANode->nodeType() == TNode<T>::NUMBER_NODE
         && FNumber == static_cast<const TNumberNode<T> *>(ANode)->FNumber;
 }
 
 // TSymbolNode
 template<typename T>
 TSymbolNode<T>::TSymbolNode(const std::string& ASymbol) :
-    TNode<T>(SYMBOL_NODE, 0), FSymbol(ASymbol) {
+    TNode<T>(TNode<T>::SYMBOL_NODE, 0), FSymbol(ASymbol) {
 }
 
 template<typename T>
@@ -139,14 +139,14 @@
 
 template<typename T>
 bool TSymbolNode<T>::equals(const TNode<T> *ANode) const {
-    return this && ANode && ANode->nodeType() == SYMBOL_NODE
+    return this && ANode && ANode->nodeType() == TNode<T>::SYMBOL_NODE
         && FSymbol == static_cast<const TSymbolNode<T> *>(ANode)->FSymbol;
 }
 
 // TParamNode
 template<typename T>
 TParamNode<T>::TParamNode() :
-    TNode<T>(PARAM_NODE, 0) {
+    TNode<T>(TNode<T>::PARAM_NODE, 0) {
 }
 
 template<typename T>
@@ -161,7 +161,7 @@
 
 template<typename T>
 bool TParamNode<T>::equals(const TNode<T> *ANode) const {
-    return this && ANode && ANode->nodeType() == PARAM_NODE;
+    return this && ANode && ANode->nodeType() == TNode<T>::PARAM_NODE;
 }
 
 // TUnaryNodeOp
@@ -186,7 +186,7 @@
 bool TUnaryNodeOp<T>::equals(const TNode<T> *ANode) const {
     // this method does not make use of the left() for performance reasons
 
-    return this && ANode && nodeType() == ANode->nodeType() &&
+    return this && ANode && this->nodeType() == ANode->nodeType() &&
         FNode->equals(static_cast<const TUnaryNodeOp<T> *>(ANode)->FNode.get());
 }
 
@@ -215,7 +215,7 @@
     // this method does not make use of the left() and right() methods 
     // for performance reasons
 
-    return this && ANode && nodeType() == ANode->nodeType() &&
+    return this && ANode && this->nodeType() == ANode->nodeType() &&
         FLeft->equals(static_cast<const TBinaryNodeOp<T> *>(ANode)->FLeft.get()) &&
         FRight->equals(static_cast<const TBinaryNodeOp<T> *>(ANode)->FRight.get());
 }
@@ -223,7 +223,7 @@
 // TPlusNode
 template<typename T>
 TPlusNode<T>::TPlusNode(TNode<T> *ALeft, TNode<T> *ARight) :
-    TBinaryNodeOp<T>(PLUS_NODE, -5, ALeft, ARight) {
+    TBinaryNodeOp<T>(TNode<T>::PLUS_NODE, -5, ALeft, ARight) {
 }
 
 template<typename T>
@@ -233,13 +233,13 @@
 
 template<typename T>
 TPlusNode<T> *TPlusNode<T>::clone() const {
-    return new TPlusNode(left()->clone(), right()->clone());
+    return new TPlusNode(this->left()->clone(), this->right()->clone());
 }
 
 // TNegNode
 template<typename T>
 TNegNode<T>::TNegNode(TNode<T> *ANode) :
-    TUnaryNodeOp<T>(NEG_NODE, -5, ANode) {
+    TUnaryNodeOp<T>(TNode<T>::NEG_NODE, -5, ANode) {
 }
 
 template<typename T>
@@ -249,13 +249,13 @@
 
 template<typename T>
 TNegNode<T> *TNegNode<T>::clone() const {
-    return new TNegNode(node()->clone());
+    return new TNegNode(this->node()->clone());
 }
 
 // TMulNode
 template<typename T>
 TMulNode<T>::TMulNode(TNode<T> *ALeft, TNode<T> *ARight) :
-    TBinaryNodeOp<T>(MUL_NODE, -3, ALeft, ARight) {
+    TBinaryNodeOp<T>(TNode<T>::MUL_NODE, -3, ALeft, ARight) {
 }
 
 template<typename T>
@@ -265,13 +265,13 @@
 
 template<typename T>
 TMulNode<T> *TMulNode<T>::clone() const {
-    return new TMulNode(left()->clone(), right()->clone());
+    return new TMulNode(this->left()->clone(), this->right()->clone());
 }
 
 // TDivNode
 template<typename T>
 TDivNode<T>::TDivNode(TNode<T> *ALeft, TNode<T> *ARight) :
-    TBinaryNodeOp<T>(DIV_NODE, -3, ALeft, ARight) {
+    TBinaryNodeOp<T>(TNode<T>::DIV_NODE, -3, ALeft, ARight) {
 }
 
 template<typename T>
@@ -281,13 +281,13 @@
 
 template<typename T>
 TDivNode<T> *TDivNode<T>::clone() const {
-    return new TDivNode(left()->clone(), right()->clone());
+    return new TDivNode(this->left()->clone(), this->right()->clone());
 }
 
 // TPowNode
 template<typename T>
 TPowNode<T>::TPowNode(TNode<T> *ALeft, TNode<T> *ARight) :
-    TBinaryNodeOp<T>(POW_NODE, -1, ALeft, ARight) {
+    TBinaryNodeOp<T>(TNode<T>::POW_NODE, -1, ALeft, ARight) {
 }
 
 template<typename T>
@@ -297,13 +297,13 @@
 
 template<typename T>
 TPowNode<T> *TPowNode<T>::clone() const {
-    return new TPowNode<T>(left()->clone(), right()->clone());
+    return new TPowNode<T>(this->left()->clone(), this->right()->clone());
 }
 
 // TSqrtNode
 template<typename T>
 TSqrtNode<T>::TSqrtNode(TNode<T> *ANode) :
-    TUnaryNodeOp<T>(SQRT_NODE, -1, ANode) {
+    TUnaryNodeOp<T>(TNode<T>::SQRT_NODE, -1, ANode) {
 }
 
 template<typename T>
@@ -313,13 +313,13 @@
 
 template<typename T>
 TSqrtNode<T> *TSqrtNode<T>::clone() const {
-    return new TSqrtNode(node()->clone());
+    return new TSqrtNode(this->node()->clone());
 }
 
 // TSinNode
 template<typename T>
 TSinNode<T>::TSinNode(TNode<T> *ANode) :
-    TUnaryNodeOp<T>(SIN_NODE, -1, ANode) {
+    TUnaryNodeOp<T>(TNode<T>::SIN_NODE, -1, ANode) {
 }
 
 template<typename T>
@@ -329,13 +329,13 @@
 
 template<typename T>
 TSinNode<T> *TSinNode<T>::clone() const {
-    return new TSinNode(node()->clone());
+    return new TSinNode(this->node()->clone());
 }
 
 // TCosNode
 template<typename T>
 TCosNode<T>::TCosNode(TNode<T> *ANode) :
-    TUnaryNodeOp<T>(COS_NODE, -1, ANode) {
+    TUnaryNodeOp<T>(TNode<T>::COS_NODE, -1, ANode) {
 }
 
 template<typename T>
@@ -345,13 +345,13 @@
 
 template<typename T>
 TCosNode<T> *TCosNode<T>::clone() const {
-    return new TCosNode(node()->clone());
+    return new TCosNode(this->node()->clone());
 }
 
 // TTanNode
 template<typename T>
 TTanNode<T>::TTanNode(TNode<T> *ANode) :
-    TUnaryNodeOp<T>(TAN_NODE, -1, ANode) {
+    TUnaryNodeOp<T>(TNode<T>::TAN_NODE, -1, ANode) {
 }
 
 template<typename T>
@@ -361,7 +361,7 @@
 
 template<typename T>
 TTanNode<T> *TTanNode<T>::clone() const {
-    return new TTanNode(node()->clone());
+    return new TTanNode(this->node()->clone());
 }
 
 // TCoTanNode
@@ -373,7 +373,7 @@
 // TLnNode
 template<typename T>
 TLnNode<T>::TLnNode(TNode<T> *ANode) :
-    TUnaryNodeOp<T>(LN_NODE, -1, ANode) {
+    TUnaryNodeOp<T>(TNode<T>::LN_NODE, -1, ANode) {
 }
 
 template<typename T>
@@ -383,13 +383,13 @@
 
 template<typename T>
 TLnNode<T> *TLnNode<T>::clone() const {
-    return new TLnNode(node()->clone());
+    return new TLnNode(this->node()->clone());
 }
 
 // TFuncNode
 template<typename T>
 TFuncNode<T>::TFuncNode(const std::string& AName, TNode<T> *AParam) :
-    TUnaryNodeOp<T>(FUNC_NODE, -1, AParam), FName(AName) {
+    TUnaryNodeOp<T>(TNode<T>::FUNC_NODE, -1, AParam), FName(AName) {
 }
 
 template<typename T>
@@ -404,13 +404,13 @@
 
 template<typename T>
 TFuncNode<T> *TFuncNode<T>::clone() const {
-    return new TFuncNode(FName, node()->clone());
+    return new TFuncNode(FName, this->node()->clone());
 }
 
 // TIfNode
 template<typename T>
 TIfNode<T>::TIfNode(TNode<T> *ACondNode, TNode<T> *AThenNode, TNode<T> *AElseNode) :
-    TBinaryNodeOp<T>(IF_NODE, -1, AThenNode, AElseNode),
+    TBinaryNodeOp<T>(TNode<T>::IF_NODE, -1, AThenNode, AElseNode),
     FCondition(ACondNode) {
 }
 
@@ -421,12 +421,12 @@
 
 template<typename T>
 TNode<T> *TIfNode<T>::trueExpr() const {
-    return left();
+    return this->left();
 }
 
 template<typename T>
 TNode<T> *TIfNode<T>::falseExpr() const {
-    return right();
+    return this->right();
 }
 
 template<typename T>
@@ -436,13 +436,13 @@
 
 template<typename T>
 TIfNode<T> *TIfNode<T>::clone() const {
-    return new TIfNode(FCondition->clone(), left()->clone(), right()->clone());
+    return new TIfNode(FCondition->clone(), this->left()->clone(), this->right()->clone());
 }
 
 // TEquNode
 template<typename T>
 TEquNode<T>::TEquNode(TNode<T> *ALeft, TNode<T> *ARight) :
-    TBinaryNodeOp<T>(EQU_NODE, -10, ALeft, ARight) {
+    TBinaryNodeOp<T>(TNode<T>::EQU_NODE, -10, ALeft, ARight) {
 }
 
 template<typename T>
@@ -452,13 +452,13 @@
 
 template<typename T>
 TEquNode<T> *TEquNode<T>::clone() const {
-    return new TEquNode<T>(left()->clone(), right()->clone());
+    return new TEquNode<T>(this->left()->clone(), this->right()->clone());
 }
 
 // TUnEquNode
 template<typename T>
 TUnEquNode<T>::TUnEquNode(TNode<T> *ALeft, TNode<T> *ARight) :
-    TBinaryNodeOp<T>(UNEQU_NODE, -10, ALeft, ARight) {
+    TBinaryNodeOp<T>(TNode<T>::UNEQU_NODE, -10, ALeft, ARight) {
 }
 
 template<typename T>
@@ -468,13 +468,13 @@
 
 template<typename T>
 TUnEquNode<T> *TUnEquNode<T>::clone() const {
-    return new TUnEquNode<T>(left()->clone(), right()->clone());
+    return new TUnEquNode<T>(this->left()->clone(), this->right()->clone());
 }
 
 // TGreaterNode
 template<typename T>
 TGreaterNode<T>::TGreaterNode(TNode<T> *ALeft, TNode<T> *ARight) :
-    TBinaryNodeOp<T>(GREATER_NODE, -10, ALeft, ARight) {
+    TBinaryNodeOp<T>(TNode<T>::GREATER_NODE, -10, ALeft, ARight) {
 }
 
 template<typename T>
@@ -484,13 +484,13 @@
 
 template<typename T>
 TGreaterNode<T> *TGreaterNode<T>::clone() const {
-    return new TGreaterNode<T>(left()->clone(), right()->clone());
+    return new TGreaterNode<T>(this->left()->clone(), this->right()->clone());
 }
 
 // TLessNode
 template<typename T>
 TLessNode<T>::TLessNode(TNode<T> *ALeft, TNode<T> *ARight) :
-    TBinaryNodeOp<T>(LESS_NODE, -10, ALeft, ARight) {
+    TBinaryNodeOp<T>(TNode<T>::LESS_NODE, -10, ALeft, ARight) {
 }
 
 template<typename T>
@@ -500,13 +500,13 @@
 
 template<typename T>
 TLessNode<T> *TLessNode<T>::clone() const {
-    return new TLessNode<T>(left()->clone(), right()->clone());
+    return new TLessNode<T>(this->left()->clone(), this->right()->clone());
 }
 
 // TGreaterEquNode
 template<typename T>
 TGreaterEquNode<T>::TGreaterEquNode(TNode<T> *ALeft, TNode<T> *ARight) :
-    TBinaryNodeOp<T>(GREATER_EQU_NODE, -10, ALeft, ARight) {
+    TBinaryNodeOp<T>(TNode<T>::GREATER_EQU_NODE, -10, ALeft, ARight) {
 }
 
 template<typename T>
@@ -516,13 +516,13 @@
 
 template<typename T>
 TGreaterEquNode<T> *TGreaterEquNode<T>::clone() const {
-    return new TGreaterEquNode<T>(left()->clone(), right()->clone());
+    return new TGreaterEquNode<T>(this->left()->clone(), this->right()->clone());
 }
 
 // TLessEquNode
 template<typename T>
 TLessEquNode<T>::TLessEquNode(TNode<T> *ALeft, TNode<T> *ARight) :
-    TBinaryNodeOp<T>(LESS_EQU_NODE, -10, ALeft, ARight) {
+    TBinaryNodeOp<T>(TNode<T>::LESS_EQU_NODE, -10, ALeft, ARight) {
 }
 
 template<typename T>
@@ -532,7 +532,7 @@
 
 template<typename T>
 TLessEquNode<T> *TLessEquNode<T>::clone() const {
-    return new TLessEquNode<T>(left()->clone(), right()->clone());
+    return new TLessEquNode<T>(this->left()->clone(), this->right()->clone());
 }
 
 } // namespace math
