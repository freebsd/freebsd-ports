--- pdb_pgsql.c.orig	2008-05-01 12:30:43.000000000 +0200
+++ pdb_pgsql.c	2008-05-01 12:41:38.000000000 +0200
@@ -164,7 +164,7 @@
 	pdb_set_profile_path         (u, PQgetvalue(r, row, 13), PDB_SET);
 	pdb_set_acct_desc            (u, PQgetvalue(r, row, 14), PDB_SET);
 	pdb_set_workstations         (u, PQgetvalue(r, row, 15), PDB_SET);
-	pdb_set_commemt              (u, PQgetvalue(r, row, 16), PDB_SET);
+	pdb_set_comment              (u, PQgetvalue(r, row, 16), PDB_SET);
 	pdb_set_munged_dial          (u, PQgetvalue(r, row, 17), PDB_SET);
  
 	pdb_set_acct_ctrl            (u, PQgetlong (r, row, 23), PDB_SET);
@@ -551,8 +551,13 @@
 static NTSTATUS pgsqlsam_init (struct pdb_methods **pdb_method, const char *location)
 {
 	NTSTATUS nt_status;
-	struct pdb_pgsql_data *data = malloc_p(struct pdb_pgsql_data);
-	
+	struct pdb_pgsql_data *data = malloc(sizeof(struct pdb_pgsql_data));
+
+	if (data == NULL) {
+		DEBUG(0, ("Can't allocate memory to data\n"));
+		return NT_STATUS_NO_MEMORY;
+	}
+
 	if (!NT_STATUS_IS_OK(nt_status = make_pdb_method(pdb_method))) {
 		return nt_status;
         }
