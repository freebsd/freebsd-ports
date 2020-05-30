--- pv/util.cpp.orig	2020-05-30 09:57:56 UTC
+++ pv/util.cpp
@@ -137,7 +137,7 @@ QString format_time_si(const Timestamp& v, SIPrefix pr
 	QString s;
 	QTextStream ts(&s);
 	if (sign && !v.is_zero())
-		ts << forcesign;
+		ts << Qt::forcesign;
 	ts << qSetRealNumberPrecision(precision) << (v * multiplier);
 	ts << ' ' << prefix << unit;
 
@@ -175,7 +175,7 @@ QString format_value_si(double v, SIPrefix prefix, uns
 	QString s;
 	QTextStream ts(&s);
 	if (sign && (v != 0))
-		ts << forcesign;
+		ts << Qt::forcesign;
 	ts.setRealNumberNotation(QTextStream::FixedNotation);
 	ts.setRealNumberPrecision(precision);
 	ts << (v * multiplier) << ' ' << prefix << unit;
