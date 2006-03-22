--- lib/ipmi_firewall.c.orig	Mon Mar 20 03:13:38 2006
+++ lib/ipmi_firewall.c	Mon Mar 20 16:21:27 2006
@@ -849,6 +849,7 @@
 	struct ipmi_function_params p = {0xe, -1, -1, -1, -1};
 	struct bmc_fn_support * bmc_fn_support;
 	unsigned int l, n, c;
+	struct command_support * cmd;
 
 	if ((argc > 0 && strncmp(argv[0], "help", 4) == 0) || ipmi_firewall_parse_args(argc, argv, &p) < 0)
 	{
@@ -886,8 +887,7 @@
 			free(bmc_fn_support);
 			return 0;
 		}
-		struct command_support * cmd =
-			&bmc_fn_support->lun[p.lun].netfn[p.netfn>>1].command[p.command];
+		cmd = &bmc_fn_support->lun[p.lun].netfn[p.netfn>>1].command[p.command];
 		c = cmd->support;
 		printf("(A)vailable, (C)onfigurable, (E)nabled: | A | C | E |\n");
 		printf("-----------------------------------------------------\n");
