--- ui/message_center/views/message_center_button_bar.cc.orig	2015-04-28 08:29:30.741134000 -0400
+++ ui/message_center/views/message_center_button_bar.cc	2015-04-28 08:31:16.302480000 -0400
@@ -94,7 +94,7 @@
     const base::string16& title)
     : message_center_view_(message_center_view),
       message_center_(message_center),
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
       close_bubble_button_(NULL),
 #endif
       title_arrow_(NULL),
@@ -169,7 +169,7 @@
                                    IDS_MESSAGE_CENTER_SETTINGS_BUTTON_LABEL);
   button_container_->AddChildView(settings_button_);
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   close_bubble_button_ = new views::ImageButton(this);
   close_bubble_button_->SetImage(
       views::Button::STATE_NORMAL,
@@ -231,7 +231,7 @@
                     0,
                     0);
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   // The close-bubble button.
   column->AddColumn(views::GridLayout::LEADING,
                     views::GridLayout::LEADING,
@@ -246,7 +246,7 @@
     layout->AddView(title_arrow_);
   layout->AddView(notification_label_);
   layout->AddView(button_container_);
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   layout->AddView(close_bubble_button_);
 #endif
 }
@@ -289,7 +289,7 @@
     else
       message_center()->EnterQuietModeWithExpire(base::TimeDelta::FromDays(1));
     quiet_mode_button_->SetToggled(message_center()->IsQuietMode());
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   } else if (sender == close_bubble_button_) {
     message_center_view()->tray()->HideMessageCenterBubble();
 #endif
