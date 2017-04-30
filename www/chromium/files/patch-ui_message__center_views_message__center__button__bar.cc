--- ui/message_center/views/message_center_button_bar.cc.orig	2017-04-19 19:06:54 UTC
+++ ui/message_center/views/message_center_button_bar.cc
@@ -95,7 +95,7 @@ MessageCenterButtonBar::MessageCenterBut
     const base::string16& title)
     : message_center_view_(message_center_view),
       message_center_(message_center),
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
       close_bubble_button_(NULL),
 #endif
       title_arrow_(NULL),
@@ -170,7 +170,7 @@ MessageCenterButtonBar::MessageCenterBut
                                    IDS_MESSAGE_CENTER_SETTINGS_BUTTON_LABEL);
   button_container_->AddChildView(settings_button_);
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   close_bubble_button_ = new views::ImageButton(this);
   close_bubble_button_->SetImage(
       views::Button::STATE_NORMAL,
@@ -232,7 +232,7 @@ void MessageCenterButtonBar::ViewVisibil
                     0,
                     0);
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   // The close-bubble button.
   column->AddColumn(views::GridLayout::LEADING,
                     views::GridLayout::LEADING,
@@ -247,7 +247,7 @@ void MessageCenterButtonBar::ViewVisibil
     layout->AddView(title_arrow_);
   layout->AddView(notification_label_);
   layout->AddView(button_container_);
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   layout->AddView(close_bubble_button_);
 #endif
 }
@@ -316,7 +316,7 @@ void MessageCenterButtonBar::ButtonPress
     else
       message_center()->EnterQuietModeWithExpire(base::TimeDelta::FromDays(1));
     quiet_mode_button_->SetToggled(message_center()->IsQuietMode());
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   } else if (sender == close_bubble_button_) {
     message_center_view()->tray()->HideMessageCenterBubble();
 #endif
