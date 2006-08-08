--- bacula-web/templates/volumes.tpl.orig	Sun Jun 19 06:17:22 2005
+++ bacula-web/templates/volumes.tpl	Sat Apr 29 16:29:36 2006
@@ -31,8 +31,8 @@
                                         <td>{$current3.0}</td>
                                         <td>{$current3.1|fsize_format|default:0}</td>
                                         <td>{$current3.4}</td>
-                                        <td {popup text="$current3.6}">{if $current3.6|date_format:"%Y" <= "1979"}--{else}{$current3.6|date_format:"%Y/%m/%d"}{/if}</td>
-                                        <td {popup text="$current3.5}">{if $current3.5 == "0000-00-00 00:00:00"}--{else}{$current3.5|date_format:"%Y/%m/%d"}{/if}</td>
+                                        <td>{if $current3.6|date_format:"%Y" <= "1979"}--{else}{$current3.6|date_format:"%Y/%m/%d"}{/if}</td>
+                                        <td>{if $current3.5 == "0000-00-00 00:00:00"}--{else}{$current3.5|date_format:"%Y/%m/%d"}{/if}</td>
                                         <td>
                                                 <font color=
                                                 {if $current3.2 == "Error"}
