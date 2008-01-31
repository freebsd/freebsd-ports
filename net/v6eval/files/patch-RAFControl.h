--- lib/pkt/RAFControl.h	2001-10-05 20:41:20.000000000 +0900
+++ lib/pkt/RAFControl.h	2008-01-01 04:49:37.000000000 +0900
@@ -69,7 +69,7 @@ virtual	const PaObject*	pop_SA(eAlgorith
 	CSTR reverseEvaluate(const McObject&,PvOctets&,bool&);
 	bool evaluateWith(RObject*,WObject*) const;
 	WObject* evaluateAlgorithm(RObject*) const;
-	WObject* RAFControl::evaluate(RObject*);
+	WObject* evaluate(RObject*);
 virtual	void reset();
 	void applyFrame(const WObject* w) const;
 	const WAlgorithm* appliedAlgorithm() const;
