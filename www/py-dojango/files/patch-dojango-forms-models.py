--- dojango/forms/models.py.orig	2013-12-19 05:09:15.062402990 -0800
+++ dojango/forms/models.py	2013-12-19 05:11:27.052422916 -0800
@@ -2,7 +2,7 @@
 from django.forms.models import BaseModelFormSet
 from django.forms.models import BaseInlineFormSet
 from django.forms.models import ModelChoiceIterator
-from django.forms.models import InlineForeignKeyHiddenInput, InlineForeignKeyField
+from django.forms.models import InlineForeignKeyField
 
 from django.utils.text import capfirst
 
@@ -32,32 +32,12 @@
 
 # Fields #####################################################################
 
-class InlineForeignKeyHiddenInput(DojoWidgetMixin, InlineForeignKeyHiddenInput):
-    """
-    Overwritten InlineForeignKeyHiddenInput to use the dojango widget mixin
-    """
-    dojo_type = 'dijit.form.TextBox' # otherwise dijit.form.Form can't get its values
-
 class InlineForeignKeyField(DojoFieldMixin, InlineForeignKeyField, Field):
     """
-    Overwritten InlineForeignKeyField to use the dojango field mixin and passing
+    Overwritten InlineForeignKeyField to use the dojango HiddenInput
     the dojango InlineForeignKeyHiddenInput as widget.
     """
-    def __init__(self, parent_instance, *args, **kwargs):
-        self.parent_instance = parent_instance
-        self.pk_field = kwargs.pop("pk_field", False)
-        self.to_field = kwargs.pop("to_field", None)
-        if self.parent_instance is not None:
-            if self.to_field:
-                kwargs["initial"] = getattr(self.parent_instance, self.to_field)
-            else:
-                kwargs["initial"] = self.parent_instance.pk
-
-        kwargs["required"] = False
-        kwargs["widget"] = InlineForeignKeyHiddenInput
-        # don't call the the superclass of this one. Use the superclass of the 
-        # normal django InlineForeignKeyField
-        Field.__init__(self, *args, **kwargs)
+    widget = HiddenInput
 
 # our customized model field => form field map
 # here it is defined which form field is used by which model field, when creating a ModelForm
