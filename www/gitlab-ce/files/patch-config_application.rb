--- config/application.rb.orig	2022-08-18 20:56:35 UTC
+++ config/application.rb
@@ -532,6 +532,25 @@ module Gitlab
 
     # DO NOT PLACE ANY INITIALIZERS AFTER THIS.
     config.after_initialize do
+      # for Rails v6.1.6.1, brought from
+      # https://gitlab.com/gitlab-org/gitlab/-/blob/e8bf6ca8f8ce38618b8e919a37b56cebc1e28773/config/application.rb
+      config.active_record.yaml_column_permitted_classes = [
+        Symbol, Date, Time,
+        BigDecimal, # https://gitlab.com/gitlab-org/gitlab/issues/368846
+        Gitlab::Diff::Position,
+        # Used in:
+        # app/models/concerns/diff_positionable_note.rb
+        # app/models/legacy_diff_note.rb:  serialize :st_diff
+        ActiveSupport::HashWithIndifferentAccess,
+        # Used in ee/lib/ee/api/helpers.rb: send_git_archive
+        DeployToken,
+        ActiveModel::Attribute.const_get(:FromDatabase, false), # https://gitlab.com/gitlab-org/gitlab/-/issues/368072
+        # Used in app/services/web_hooks/log_execution_service.rb: log_execution
+        ActiveSupport::TimeWithZone,
+        ActiveSupport::TimeZone,
+        Gitlab::Color # https://gitlab.com/gitlab-org/gitlab/-/issues/368844
+      ]
+
       # on_master_start yields immediately in unclustered environments and runs
       # when the primary process is done initializing otherwise.
       Gitlab::Cluster::LifecycleEvents.on_master_start do
