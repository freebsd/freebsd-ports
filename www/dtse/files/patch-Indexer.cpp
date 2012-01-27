--- ./Indexer.cpp.orig	2008-08-23 04:00:12.000000000 -0700
+++ ./Indexer.cpp	2011-12-30 17:37:16.000000000 -0800
@@ -286,6 +286,8 @@
 				case all:
 					restrictionsAll.insert(restriction.getURL());
 					break;
+				default:
+					break;
 				}
 			}
 		}
@@ -332,6 +334,8 @@
 				restrictions.insert(*itor);
 			}
 			break;
+		default:
+			break;
 		}
 
 		cout << "done.\n";
