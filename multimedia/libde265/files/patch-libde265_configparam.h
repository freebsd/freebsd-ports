--- libde265/configparam.h.orig	2025-04-26 19:56:15 UTC
+++ libde265/configparam.h
@@ -95,7 +95,7 @@ class option_base
   bool hasLongOption() const { return true; } //mLongOption!=NULL; }
   std::string getLongOption() const { return mLongOption ? std::string(mLongOption) : get_name(); }
 
-  virtual LIBDE265_API bool processCmdLineArguments(char** argv, int* argc, int idx) { return false; }
+  virtual bool processCmdLineArguments(char** argv, int* argc, int idx) { return false; }
 
 
 
@@ -132,7 +132,7 @@ class option_bool : public option_base (public)
   virtual std::string get_default_string() const { return default_value ? "true":"false"; }
 
   virtual std::string getTypeDescr() const { return "(boolean)"; }
-  virtual LIBDE265_API bool processCmdLineArguments(char** argv, int* argc, int idx) { set(true); return true; }
+  virtual bool processCmdLineArguments(char** argv, int* argc, int idx) { set(true); return true; }
 
   bool set(bool v) { value_set=true; value=v; return true; }
 
@@ -162,10 +162,10 @@ class option_string : public option_base (public)
   virtual bool has_default() const { return default_set; }
 
   void set_default(std::string v) { default_value=v; default_set=true; }
-  virtual LIBDE265_API std::string get_default_string() const { return default_value; }
+  virtual std::string get_default_string() const { return default_value; }
 
-  virtual LIBDE265_API std::string getTypeDescr() const { return "(string)"; }
-  virtual LIBDE265_API bool processCmdLineArguments(char** argv, int* argc, int idx);
+  virtual std::string getTypeDescr() const { return "(string)"; }
+  virtual bool processCmdLineArguments(char** argv, int* argc, int idx);
 
   bool set(std::string v) { value_set=true; value=v; return true; }
 
@@ -201,10 +201,10 @@ class option_int : public option_base (public)
   virtual bool has_default() const { return default_set; }
 
   void set_default(int v) { default_value=v; default_set=true; }
-  virtual LIBDE265_API std::string get_default_string() const;
+  virtual std::string get_default_string() const;
 
-  virtual LIBDE265_API std::string getTypeDescr() const;
-  virtual LIBDE265_API bool processCmdLineArguments(char** argv, int* argc, int idx);
+  virtual std::string getTypeDescr() const;
+  virtual bool processCmdLineArguments(char** argv, int* argc, int idx);
 
   bool set(int v) {
     if (is_valid(v)) { value_set=true; value=v; return true; }
@@ -239,7 +239,7 @@ class choice_option_base : public option_base (public)
   virtual std::vector<std::string> get_choice_names() const = 0;
 
   virtual std::string getTypeDescr() const;
-  virtual LIBDE265_API bool processCmdLineArguments(char** argv, int* argc, int idx);
+  virtual bool processCmdLineArguments(char** argv, int* argc, int idx);
 
   const char** get_choices_string_table() const;
 
@@ -368,10 +368,10 @@ class config_parameters
  config_parameters() : param_string_table(NULL) { }
   ~config_parameters() { delete[] param_string_table; }
 
-  void LIBDE265_API add_option(option_base* o);
+  void add_option(option_base* o);
 
-  void LIBDE265_API print_params() const;
-  bool LIBDE265_API parse_command_line_params(int* argc, char** argv, int* first_idx=NULL,
+  void print_params() const;
+  bool parse_command_line_params(int* argc, char** argv, int* first_idx=NULL,
                                  bool ignore_unknown_options=false);
 
 
