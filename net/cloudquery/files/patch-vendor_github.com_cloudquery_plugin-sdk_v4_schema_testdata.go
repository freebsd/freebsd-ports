--- vendor/github.com/cloudquery/plugin-sdk/v4/schema/testdata.go.orig	2026-08-26 19:43:19 UTC
+++ vendor/github.com/cloudquery/plugin-sdk/v4/schema/testdata.go
@@ -460,11 +460,11 @@ func (tg TestDataGenerator) getExampleJSON(colName str
 			case arrow.FixedWidthTypes.Time64us:
 				h, m, s := t.Clock()
 				ns := t.Nanosecond()
-				return strconv.Itoa(h*3600000000 + m*60000000 + s*1000000 + ns/1000)
+				return strconv.FormatInt(int64(h)*3600000000+int64(m)*60000000+int64(s)*1000000+int64(ns)/1000, 10)
 			case arrow.FixedWidthTypes.Time64ns:
 				h, m, s := t.Clock()
 				ns := t.Nanosecond()
-				return strconv.Itoa(h*3600000000000 + m*60000000000 + s*1000000000 + ns)
+				return strconv.FormatInt(int64(h)*3600000000000 + int64(m)*60000000000 + int64(s)*1000000000 + int64(ns), 10)
 			default:
 				panic("unhandled timestamp type: " + timestampType.Name())
 			}
