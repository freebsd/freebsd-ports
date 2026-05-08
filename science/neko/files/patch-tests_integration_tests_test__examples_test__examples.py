-- Filter examples to only those present in the distribution and use gmake
-- This patch is needed to ensure tests pass on FreeBSD
-- Filter examples to only those present in the distribution and use gmake
-- This patch is needed to ensure tests pass on FreeBSD
--- tests/integration/tests/test_examples/test_examples.py.orig	2026-05-08 17:08:44 UTC
+++ tests/integration/tests/test_examples/test_examples.py
@@ -20,7 +20,7 @@ examples_dir = join(neko_dir, "examples")
 
 examples_dir = join(neko_dir, "examples")
 
-examples = {
+all_examples = {
     "2d_cylinder": NekoTestCase(
         case_file=join(examples_dir, "2d_cylinder", "2d_cylinder.case"),
         user_file=join(examples_dir, "2d_cylinder", "2d_cylinder.f90"),
@@ -123,6 +123,7 @@ examples = {
         user_file=join(examples_dir, "programming", "user_file_template.f90")
     ),
 }
+examples = {k: v for k, v in all_examples.items() if k in ['2d_cylinder', 'cyl_boundary_layer', 'hemi', 'lid', 'rayleigh_benard', 'rayleigh_benard_cylinder', 'tgv', 'turb_channel', 'turb_pipe']}
 
 
 def manipulate_case(example, case, tmp_path):
@@ -149,7 +150,7 @@ def manipulate_case(example, case, tmp_path):
     case_object["output_directory"] = str(tmp_path)
 
 
-@pytest.mark.parametrize("example", ["hemi", "rayleigh_benard", "cylinder"])
+@pytest.mark.parametrize("example", ["hemi", "rayleigh_benard", "2d_cylinder"])
 #@pytest.mark.parametrize("example", examples.keys())
 def test_example_smoke(example, launcher_script, request, log_file, tmp_path):
     """Run a smoke test for the specified Neko example.
@@ -222,7 +223,7 @@ def test_example_poisson(log_file):
     """
 
     result = subprocess.run(
-            ["make", "-C", join(examples_dir, "poisson")],
+            ["gmake", "-C", join(examples_dir, "poisson")],
             stdout=subprocess.PIPE,
             stderr=subprocess.STDOUT,
             text=True)
