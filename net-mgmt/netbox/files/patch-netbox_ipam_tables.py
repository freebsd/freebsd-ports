Fix unable to assign existing IP addresses to interfaces

Obtained from:
https://github.com/netbox-community/netbox/commit/1acdf58a4bb35d83a280464ac69aa961ff614df7

--- netbox/ipam/tables.py.orig	2019-12-15 11:43:12 UTC
+++ netbox/ipam/tables.py
@@ -85,7 +85,11 @@ IPADDRESS_LINK = """
 """
 
 IPADDRESS_ASSIGN_LINK = """
-<a href="{% url 'ipam:ipaddress_edit' pk=record.pk %}?interface={{ record.interface.pk }}&return_url={{ request.path }}">{{ record }}</a>
+{% if request.GET %}
+    <a href="{% url 'ipam:ipaddress_edit' pk=record.pk %}?interface={{ request.GET.interface }}&return_url={{ request.GET.return_url }}">{{ record }}</a>
+{% else %}
+    <a href="{% url 'ipam:ipaddress_edit' pk=record.pk %}?interface={{ record.interface.pk }}&return_url={{ request.path }}">{{ record }}</a>
+{% endif %}
 """
 
 IPADDRESS_PARENT = """
