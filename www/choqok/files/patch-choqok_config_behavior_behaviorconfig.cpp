--- choqok/config/behavior/behaviorconfig.cpp.orig	2020-02-05 11:49:13 UTC
+++ choqok/config/behavior/behaviorconfig.cpp
@@ -95,9 +95,9 @@ BehaviorConfig::BehaviorConfig(QWidget *parent, const 
     d->mBehaviorTabCtl->addTab(d->proxyModule, proxyInfo.moduleName());
 
     connect(d->mPrfsShorten, (void (BehaviorConfig_Shorten::*)(bool))&BehaviorConfig_Shorten::changed,
-            this, (void (KCModule::*)())&KCModule::changed);
+            this, &BehaviorConfig::markAsChanged);
     connect(d->proxyModule, (void (KCModuleProxy::*)(KCModuleProxy*))&KCModuleProxy::changed,
-            this, (void (KCModule::*)())&KCModule::changed);
+            this, &BehaviorConfig::markAsChanged);
 
     load();
 
