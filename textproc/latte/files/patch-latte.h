--- latte.h.orig	Fri Oct 22 12:20:46 1999
+++ latte.h	Fri Mar 19 01:40:45 2004
@@ -76,11 +76,11 @@
   unsigned int m_spaces;
   unsigned int m_newlines;
 
-  friend ostream &operator << (ostream &, const Latte_Wstate &);
+  friend std::ostream &operator << (std::ostream &, const Latte_Wstate &);
 };
 
-extern ostream &
-operator << (ostream &, const Latte_Wstate &);
+extern std::ostream &
+operator << (std::ostream &, const Latte_Wstate &);
 
 class Latte_FileLoc {
  public:
@@ -100,8 +100,8 @@
   unsigned int m_lineno;
 };
 
-extern ostream &
-operator << (ostream &, const Latte_FileLoc &);
+extern std::ostream &
+operator << (std::ostream &, const Latte_FileLoc &);
 
 class Latte_Error : public Latte_FileLoc {
  public:
@@ -238,19 +238,19 @@
 
   virtual void visit(Latte_Visitor &) = 0;
 
-  virtual void render(ostream &out) const;
+  virtual void render(std::ostream &out) const;
 
   Refcounter<Latte_Obj> eval(Latte_Activation &);
 
  protected:
   virtual Refcounter<Latte_Obj> do_eval(Latte_Activation &);
 
-  friend Latte_Nested;
-  friend Latte_WsNode;
+  friend class Latte_Nested;
+  friend class Latte_WsNode;
 };
 
-extern ostream &
-operator << (ostream &, const Latte_Obj &);
+extern std::ostream &
+operator << (std::ostream &, const Latte_Obj &);
 
 class Latte_Nested : virtual public Latte_Obj {
  public:
@@ -305,7 +305,7 @@
 
   void visit(Latte_Visitor &);
 
-  void render(ostream &out) const { m_nested->render(out); }
+  void render(std::ostream &out) const { m_nested->render(out); }
 
   void set_nested_obj(const Refcounter<Latte_Obj> &obj);
   const Refcounter<Latte_Obj> &nested_obj() const { return m_nested; }
@@ -344,9 +344,9 @@
   memo<bool, SideEffectFn> m_side_effect;
   memo<Latte_Operator *, GetOperatorFn> m_operator;
 
-  friend SelfEvalFn;
-  friend SideEffectFn;
-  friend GetOperatorFn;
+  friend class SelfEvalFn;
+  friend class SideEffectFn;
+  friend class GetOperatorFn;
 };
 
 class Latte_WsNode : public Latte_Nested,
@@ -381,7 +381,7 @@
 
   void visit(Latte_Visitor &);
 
-  void render(ostream &) const;
+  void render(std::ostream &) const;
 
  private:
   bool m_val;
@@ -430,7 +430,7 @@
 
   void visit(Latte_Visitor &);
 
-  void render(ostream &) const;
+  void render(std::ostream &) const;
 
   bool self_evaluating() const { return 0; }
   bool side_effects() const;
@@ -466,7 +466,7 @@
 
   void visit(Latte_Visitor &);
 
-  void render(ostream &) const;
+  void render(std::ostream &) const;
 
  private:
   Type m_type;
@@ -518,7 +518,7 @@
 
   void visit(Latte_Visitor &);
 
-  void render(ostream &) const;
+  void render(std::ostream &) const;
 
  protected:
   Refcounter<Latte_Obj> do_eval(Latte_Activation &);
@@ -560,7 +560,7 @@
   bool self_evaluating() const { return m_self_eval.val(); }
   void visit(Latte_Visitor &);
 
-  void render(ostream &) const;
+  void render(std::ostream &) const;
 
  protected:
   Refcounter<Latte_Obj> do_eval(Latte_Activation &);
@@ -729,7 +729,7 @@
 
   void visit(Latte_Visitor &);
 
-  void render(ostream &) const;
+  void render(std::ostream &) const;
 
   bool self_evaluating() const { return 0; }
 
@@ -755,7 +755,7 @@
 
   void visit(Latte_Visitor &);
 
-  void render(ostream &) const;
+  void render(std::ostream &) const;
 
  private:
   mutable bool m_numval_known;
@@ -780,7 +780,7 @@
 
   void visit(Latte_Visitor &);
 
-  void render(ostream &) const;
+  void render(std::ostream &) const;
 
   class Undefined : public Latte_Error {
    public:
@@ -866,8 +866,8 @@
 
 class Latte_Reader : public latteFlexLexer {
  public:
-  Latte_Reader(istream &, const shstring &);
-  Latte_Reader(istream &, const shstring &, Latte_Activation &);
+  Latte_Reader(std::istream &, const shstring &);
+  Latte_Reader(std::istream &, const shstring &, Latte_Activation &);
 
   int yylex();
   void process(Latte_Visitor &);
