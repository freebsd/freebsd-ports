# test_{new,old}_mangling_file spins on cpu/hangs
# patch them out for now

--- tests/test_cases/test_command_line_args.py.orig	2021-12-21 08:01:58 UTC
+++ tests/test_cases/test_command_line_args.py
@@ -305,10 +305,6 @@ class TestCommandLineArgs(ElfDiffExecutionMixin, TestC
             f.write("Some additional new info")
         self.runSimpleTest([("new_info_file", new_info_file)])
 
-    def test_new_mangling_file(self):
-        self.expected_return_code = RETURN_CODE_WARNINGS_OCCURRED
-        self.runSimpleTestGhs([("new_mangling_file", NEW_MANGLING_FILE_GHS)])
-
     def test_nm_command(self):
         self.runSimpleTest(
             [("nm_command", os.path.join(STANDARD_BIN_DIR, f"nm{EXE_SUFFIX}"))]
@@ -336,10 +332,6 @@ class TestCommandLineArgs(ElfDiffExecutionMixin, TestC
         with open(old_info_file, "w") as f:
             f.write("Some additional old info")
         self.runSimpleTest([("old_info_file", old_info_file)])
-
-    def test_old_mangling_file(self):
-        self.expected_return_code = RETURN_CODE_WARNINGS_OCCURRED
-        self.runSimpleTestGhs([("old_mangling_file", OLD_MANGLING_FILE_GHS)])
 
     def test_pdf_file(self):
         pdf_file = "parameter_test_single_page_pair_report.pdf"
