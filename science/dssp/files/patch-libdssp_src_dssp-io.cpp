--- libdssp/src/dssp-io.cpp.orig	2026-03-21 21:49:26.455057000 -0700
+++ libdssp/src/dssp-io.cpp	2026-03-21 21:49:47.132217000 -0700
@@ -276,7 +276,7 @@
 					data.emplace_back("acceptor_1_auth_seq_id", acceptor.auth_seq_id());
 					data.emplace_back("acceptor_1_auth_asym_id", acceptor.auth_asym_id());
 					data.emplace_back("acceptor_1_pdbx_PDB_ins_code", acceptor.pdb_ins_code());
-					data.emplace_back("acceptor_1_energy", acceptorEnergy, 1);
+					data.emplace_back("acceptor_1_energy", cif::item_value{acceptorEnergy, 1});
 				}
 				else
 				{
@@ -287,7 +287,7 @@
 					data.emplace_back("acceptor_2_auth_seq_id", acceptor.auth_seq_id());
 					data.emplace_back("acceptor_2_auth_asym_id", acceptor.auth_asym_id());
 					data.emplace_back("acceptor_2_pdbx_PDB_ins_code", acceptor.pdb_ins_code());
-					data.emplace_back("acceptor_2_energy", acceptorEnergy, 1);
+					data.emplace_back("acceptor_2_energy", cif::item_value{acceptorEnergy, 1});
 				}
 			}
 
@@ -302,7 +302,7 @@
 					data.emplace_back("donor_1_auth_seq_id", donor.auth_seq_id());
 					data.emplace_back("donor_1_auth_asym_id", donor.auth_asym_id());
 					data.emplace_back("donor_1_pdbx_PDB_ins_code", donor.pdb_ins_code());
-					data.emplace_back("donor_1_energy", donorEnergy, 1);
+					data.emplace_back("donor_1_energy", cif::item_value{donorEnergy, 1});
 				}
 				else
 				{
@@ -313,7 +313,7 @@
 					data.emplace_back("donor_2_auth_seq_id", donor.auth_seq_id());
 					data.emplace_back("donor_2_auth_asym_id", donor.auth_asym_id());
 					data.emplace_back("donor_2_pdbx_PDB_ins_code", donor.pdb_ins_code());
-					data.emplace_back("donor_2_energy", donorEnergy, 1);
+					data.emplace_back("donor_2_energy", cif::item_value{donorEnergy, 1});
 				}
 			}
 		}
@@ -525,30 +525,30 @@
 		{ "nr_of_ss_bridges_total", stats.count.SS_bridges },
 		{ "nr_of_ss_bridges_intra_chain", stats.count.intra_chain_SS_bridges },
 		{ "nr_of_ss_bridges_inter_chain", stats.count.SS_bridges - stats.count.intra_chain_SS_bridges },
-		{ "accessible_surface_of_protein", surface_accessibility, 2 } });
+		{ "accessible_surface_of_protein", cif::item_value{surface_accessibility} } });
 
 	auto &dssp_struct_hbonds = db["dssp_statistics_hbond"];
 
 	dssp_struct_hbonds.emplace({ { "entry_id", db.name() },
 		{ "type", "O(I)-->H-N(J)" },
 		{ "count", stats.count.H_bonds },
-		{ "count_per_100", stats.count.H_bonds * 100.0 / stats.count.residues, 1 } });
+		{ "count_per_100", cif::item_value{stats.count.H_bonds * 100.0 / stats.count.residues, 1} } });
 
 	dssp_struct_hbonds.emplace({ { "entry_id", db.name() },
 		{ "type", "PARALLEL BRIDGES" },
 		{ "count", stats.count.H_bonds_in_parallel_bridges },
-		{ "count_per_100", stats.count.H_bonds_in_parallel_bridges * 100.0 / stats.count.residues, 1 } });
+		{ "count_per_100", cif::item_value{stats.count.H_bonds_in_parallel_bridges * 100.0 / stats.count.residues, 1} } });
 
 	dssp_struct_hbonds.emplace({ { "entry_id", db.name() },
 		{ "type", "ANTIPARALLEL BRIDGES" },
 		{ "count", stats.count.H_bonds_in_antiparallel_bridges },
-		{ "count_per_100", stats.count.H_bonds_in_antiparallel_bridges * 100.0 / stats.count.residues, 1 } });
+		{ "count_per_100", cif::item_value{stats.count.H_bonds_in_antiparallel_bridges * 100.0 / stats.count.residues, 1} } });
 
 	for (int k = 0; k < 11; ++k)
 		dssp_struct_hbonds.emplace({ { "entry_id", db.name() },
 			{ "type", "O(I)-->H-N(I"s + (k - 5 < 0 ? '-' : '+') + std::to_string(abs(k - 5)) + ")" },
 			{ "count", stats.count.H_Bonds_per_distance[k] },
-			{ "count_per_100", stats.count.H_Bonds_per_distance[k] * 100.0 / stats.count.residues, 1 } });
+			{ "count_per_100", cif::item_value{stats.count.H_Bonds_per_distance[k] * 100.0 / stats.count.residues, 1} } });
 
 	auto &dssp_statistics_histogram = db["dssp_statistics_histogram"];
 
@@ -701,36 +701,36 @@
 			{ "ladder_1", ladders[0] },
 			{ "ladder_2", ladders[1] },
 
-			{ "x_ca", cax, 1 },
-			{ "y_ca", cay, 1 },
-			{ "z_ca", caz, 1 },
+			{ "x_ca", cif::item_value{cax, 1} },
+			{ "y_ca", cif::item_value{cay, 1} },
+			{ "z_ca", cif::item_value{caz, 1} },
 		};
 
 		if (writeAccessibility)
-			data.emplace_back("accessibility", res.accessibility(), 1);
+			data.emplace_back("accessibility", cif::item_value{res.accessibility(), 1});
 
 		if (res.tco().has_value())
-			data.emplace_back("TCO", *res.tco(), 3);
+			data.emplace_back("TCO", cif::item_value{*res.tco(), 3});
 		else
 			data.emplace_back("TCO", ".");
 
 		if (res.kappa().has_value())
-			data.emplace_back("kappa", *res.kappa(), 1);
+			data.emplace_back("kappa", cif::item_value{*res.kappa(), 1});
 		else
 			data.emplace_back("kappa", ".");
 
 		if (res.alpha().has_value())
-			data.emplace_back("alpha", *res.alpha(), 1);
+			data.emplace_back("alpha", cif::item_value{*res.alpha(), 1});
 		else
 			data.emplace_back("alpha", ".");
 
 		if (res.phi().has_value())
-			data.emplace_back("phi", *res.phi(), 1);
+			data.emplace_back("phi", cif::item_value{*res.phi(), 1});
 		else
 			data.emplace_back("phi", ".");
 
 		if (res.psi().has_value())
-			data.emplace_back("psi", *res.psi(), 1);
+			data.emplace_back("psi", cif::item_value{*res.psi(), 1});
 		else
 			data.emplace_back("psi", ".");
 
@@ -757,7 +757,6 @@
 
 	if (audit_conform.empty())
 	{
-		static_assert(std::is_reference_v<decltype(std::declval<cif::validator_factory>().get(""))>);
 		fill_audit_conform<cif::validator_factory>(audit_conform);
 	}
 
