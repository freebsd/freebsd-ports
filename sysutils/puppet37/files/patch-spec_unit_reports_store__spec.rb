--- spec/unit/reports/store_spec.rb.orig	2015-03-25 16:32:48 UTC
+++ spec/unit/reports/store_spec.rb
@@ -24,7 +24,7 @@ describe processor do
     end
 
     it "should write the report to the file in YAML" do
-      Time.stubs(:now).returns(Time.parse("2011-01-06 12:00:00 UTC"))
+      Time.stubs(:now).returns(Time.utc(2011,01,06,12,00,00))
       @report.process
 
       File.read(File.join(Puppet[:reportdir], @report.host, "201101061200.yaml")).should == @report.to_yaml
