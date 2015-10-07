--- pootle/apps/pootle_terminology/views.py.orig	2015-06-03 13:30:23 UTC
+++ pootle/apps/pootle_terminology/views.py
@@ -19,7 +19,7 @@
 # Pootle; if not, see <http://www.gnu.org/licenses/>.
 
 from django.conf import settings
-from django.db.transaction import commit_on_success
+from django.db import transaction
 from django.shortcuts import render_to_response
 from django.template import RequestContext
 from django.utils.translation import ugettext as _
@@ -63,7 +63,7 @@ def get_terminology_filename(translation
     return 'pootle-terminology.' + translation_project.project.localfiletype
 
 
-@commit_on_success
+@transaction.atomic
 @get_path_obj
 @permission_required('administrate')
 def extract(request, translation_project):
