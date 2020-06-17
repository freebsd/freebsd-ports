--- Bindings/common.i.orig	2020-02-01 04:17:56 UTC
+++ Bindings/common.i
@@ -353,9 +353,11 @@ DATATABLE_CLONE(double, SimTK::Rotation_<double>)
 
 %include <OpenSim/Common/Event.h>
 %template(StdVectorEvent) std::vector<OpenSim::Event>;
+/*
 %template(StdMapStringTimeSeriesTableVec3)
         std::map<std::string, 
                  std::shared_ptr<OpenSim::TimeSeriesTable_<SimTK::Vec3>>>;
+*/
 %shared_ptr(OpenSim::DataAdapter)
 %shared_ptr(OpenSim::FileAdapter)
 %shared_ptr(OpenSim::DelimFileAdapter)
