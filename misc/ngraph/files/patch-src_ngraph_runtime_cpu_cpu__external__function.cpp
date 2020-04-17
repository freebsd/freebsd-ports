--- src/ngraph/runtime/cpu/cpu_external_function.cpp.orig	2020-04-17 03:39:33 UTC
+++ src/ngraph/runtime/cpu/cpu_external_function.cpp
@@ -913,6 +913,7 @@ using namespace ngraph::runtime;
                                         t_out_attrs,
                                         t_in_attrs);
             }
+#if defined(NGRAPH_TBB_ENABLE)
             if (m_use_tbb)
             {
                 writer << "tbb::flow::continue_node<tbb::flow::continue_msg>* "
@@ -922,6 +923,7 @@ using namespace ngraph::runtime;
                           "(*(cg_ctx->tbb_graph), [&](const tbb::flow::continue_msg &msg)\n{\n";
                 writer.indent++;
             }
+#endif
             if (runtime::cpu::IsTracingEnabled() && m_function->get_name() == m_function_name)
             {
                 writer << "start_ts = cpu::Clock::now();\n";
