# New ports collection makefile for:	drupal6-chaos
# Date created:		09 Feb 2010
# Whom:			anderson@cnpm.embrapa.br
#
# $FreeBSD$
#

PORTNAME=	ctools
DISTVERSION=	6.x-1.6
CATEGORIES=	www
MASTER_SITES=	http://ftp.drupal.org/files/projects/

MAINTAINER=	anderson@cnpm.embrapa.br
COMMENT=	Drupal 6.x Chaos tool suite module

DRUPAL6_MODULE=	yes

MODULE_DIRS=	views_content/translations views_content/plugins/views/translations \
		views_content/plugins/views views_content/plugins/content_types/translations \
		views_content/plugins/content_types views_content/plugins \
		views_content translations plugins/relationships/translations plugins/relationships \
		plugins/contexts/translations plugins/contexts \
		plugins/content_types/vocabulary_context/translations plugins/content_types/vocabulary_context \
		plugins/content_types/user_context/translations plugins/content_types/user_context \
		plugins/content_types/term_context/translations plugins/content_types/term_context \
		plugins/content_types/search/translations plugins/content_types/search \
		plugins/content_types/page/translations plugins/content_types/page \
		plugins/content_types/node_form/translations plugins/content_types/node_form \
		plugins/content_types/node_context/translations plugins/content_types/node_context \
		plugins/content_types/node/translations plugins/content_types/node \
		plugins/content_types/form/translations plugins/content_types/form \
		plugins/content_types/custom/translations plugins/content_types/custom \
		plugins/content_types/contact/translations plugins/content_types/contact \
		plugins/content_types/block/translations plugins/content_types/block \
		plugins/content_types plugins/arguments/translations \
		plugins/arguments plugins/access/translations \
		plugins/access plugins page_manager/translations \
		page_manager/theme/translations page_manager/theme \
		page_manager/plugins/tasks/translations page_manager/plugins/tasks \
		page_manager/plugins page_manager/js page_manager/images page_manager/help \
		page_manager/css page_manager js includes/translations includes \
		images help delegator ctools_plugin_example/translations \
		ctools_plugin_example/plugins/relationships/translations \
		ctools_plugin_example/plugins/relationships \
		ctools_plugin_example/plugins/contexts/translations \
		ctools_plugin_example/plugins/contexts \
		ctools_plugin_example/plugins/content_types/translations \
		ctools_plugin_example/plugins/content_types \
		ctools_plugin_example/plugins/arguments/translations \
		ctools_plugin_example/plugins/arguments \
		ctools_plugin_example/plugins/access/translations \
		ctools_plugin_example/plugins/access ctools_plugin_example/plugins \
		ctools_plugin_example/help ctools_plugin_example css \
		bulk_export/translations bulk_export

MODULE_FILES=	views_content/views_content.module \
		views_content/views_content.info \
		views_content/views_content.admin.inc \
		views_content/translations/views_content.pot \
		views_content/translations/views_content.hu.po \
		views_content/translations/views_content.fr.po \
		views_content/translations/views_content.de.po \
		views_content/plugins/views/views_content_plugin_display_panel_pane.inc \
		views_content/plugins/views/views_content.views.inc \
		views_content/plugins/views/translations/views_content-plugins-views.hu.po \
		views_content/plugins/content_types/views_panes.inc \
		views_content/plugins/content_types/views.inc \
		views_content/plugins/content_types/translations/views_content-plugins-content_types.hu.po \
		views_content/plugins/content_types/icon_views_page_legacy.png \
		views_content/plugins/content_types/icon_views_page.png \
		views_content/plugins/content_types/icon_views_block_legacy.png \
		translations/general.pot \
		translations/general.hu.po \
		translations/general.de.po \
		translations/ctools.pot \
		translations/ctools.hu.po \
		translations/ctools.fr.po \
		translations/ctools.de.po \
		plugins/relationships/user_from_node.inc \
		plugins/relationships/translations/plugins-relationships.hu.po \
		plugins/relationships/terms_from_node.inc \
		plugins/relationships/term_parent.inc \
		plugins/relationships/term_from_node.inc \
		plugins/relationships/book_parent.inc \
		plugins/contexts/vocabulary.inc \
		plugins/contexts/user.inc \
		plugins/contexts/translations/plugins-contexts.hu.po \
		plugins/contexts/token.inc \
		plugins/contexts/terms.inc \
		plugins/contexts/term.inc \
		plugins/contexts/string.inc \
		plugins/contexts/node_edit_form.inc \
		plugins/contexts/node_add_form.inc \
		plugins/contexts/node.inc \
		plugins/content_types/vocabulary_context/vocabulary_terms.inc \
		plugins/content_types/vocabulary_context/translations/plugins-content_types-vocabulary_context.hu.po \
		plugins/content_types/vocabulary_context/icon_vocabulary.png \
		plugins/content_types/user_context/user_profile.inc \
		plugins/content_types/user_context/user_picture.inc \
		plugins/content_types/user_context/translations/plugins-content_types-user_context.hu.po \
		plugins/content_types/user_context/profile_fields_pane.tpl.php \
		plugins/content_types/user_context/profile_fields.inc \
		plugins/content_types/user_context/icon_user.png \
		plugins/content_types/term_context/translations/plugins-content_types-term_context.hu.po \
		plugins/content_types/term_context/term_list.inc \
		plugins/content_types/term_context/term_description.inc \
		plugins/content_types/term_context/icon_term.png \
		plugins/content_types/search/translations/plugins-content_types-search.hu.po \
		plugins/content_types/search/search_result.inc \
		plugins/content_types/search/search_form.inc \
		plugins/content_types/search/icon_search.png \
		plugins/content_types/page/translations/plugins-content_types-page.hu.po \
		plugins/content_types/page/page_title.inc \
		plugins/content_types/page/page_tabs.inc \
		plugins/content_types/page/page_slogan.inc \
		plugins/content_types/page/page_site_name.inc \
		plugins/content_types/page/page_secondary_links.inc \
		plugins/content_types/page/page_primary_links.inc \
		plugins/content_types/page/page_mission.inc \
		plugins/content_types/page/page_messages.inc \
		plugins/content_types/page/page_logo.inc \
		plugins/content_types/page/page_help.inc \
		plugins/content_types/page/page_footer_message.inc \
		plugins/content_types/page/page_feed_icons.inc \
		plugins/content_types/page/page_breadcrumb.inc \
		plugins/content_types/node_form/translations/plugins-content_types-node_form.hu.po \
		plugins/content_types/node_form/node_form_taxonomy.inc \
		plugins/content_types/node_form/node_form_publishing.inc \
		plugins/content_types/node_form/node_form_path.inc \
		plugins/content_types/node_form/node_form_menu.inc \
		plugins/content_types/node_form/node_form_log.inc \
		plugins/content_types/node_form/node_form_input_format.inc \
		plugins/content_types/node_form/node_form_comment.inc \
		plugins/content_types/node_form/node_form_buttons.inc \
		plugins/content_types/node_form/node_form_book.inc \
		plugins/content_types/node_form/node_form_author.inc \
		plugins/content_types/node_form/node_form_attachments.inc \
		plugins/content_types/node_form/icon_node_form.png \
		plugins/content_types/node_context/translations/plugins-content_types-node_context.hu.po \
		plugins/content_types/node_context/node_updated.inc \
		plugins/content_types/node_context/node_type_desc.inc \
		plugins/content_types/node_context/node_title.inc \
		plugins/content_types/node_context/node_terms.inc \
		plugins/content_types/node_context/node_links.inc \
		plugins/content_types/node_context/node_created.inc \
		plugins/content_types/node_context/node_content.inc \
		plugins/content_types/node_context/node_comments.inc \
		plugins/content_types/node_context/node_comment_form.inc \
		plugins/content_types/node_context/node_book_nav.inc \
		plugins/content_types/node_context/node_book_children.inc \
		plugins/content_types/node_context/node_body.inc \
		plugins/content_types/node_context/node_author.inc \
		plugins/content_types/node_context/node_attachments.inc \
		plugins/content_types/node_context/icon_node.png \
		plugins/content_types/node/translations/plugins-content_types-node.hu.po \
		plugins/content_types/node/node.inc \
		plugins/content_types/node/icon_node.png \
		plugins/content_types/form/translations/plugins-content_types-form.hu.po \
		plugins/content_types/form/icon_form.png \
		plugins/content_types/form/form.inc \
		plugins/content_types/custom/translations/plugins-content_types-custom.hu.po \
		plugins/content_types/custom/icon_block_custom.png \
		plugins/content_types/custom/custom.inc \
		plugins/content_types/contact/user_contact.inc \
		plugins/content_types/contact/translations/plugins-content_types-contact.hu.po \
		plugins/content_types/contact/icon_contact.png \
		plugins/content_types/contact/contact.inc \
		plugins/content_types/block/translations/plugins-content_types-block.hu.po \
		plugins/content_types/block/icon_core_whosonline.png \
		plugins/content_types/block/icon_core_whosnew.png \
		plugins/content_types/block/icon_core_userlogin.png \
		plugins/content_types/block/icon_core_syndicate.png \
		plugins/content_types/block/icon_core_searchform.png \
		plugins/content_types/block/icon_core_recentpoll.png \
		plugins/content_types/block/icon_core_recentcomments.png \
		plugins/content_types/block/icon_core_recentblogposts.png \
		plugins/content_types/block/icon_core_primarylinks.png \
		plugins/content_types/block/icon_core_popularcontent.png \
		plugins/content_types/block/icon_core_page.png \
		plugins/content_types/block/icon_core_newforumtopics.png \
		plugins/content_types/block/icon_core_navigation.png \
		plugins/content_types/block/icon_core_languageswitcher.png \
		plugins/content_types/block/icon_core_booknavigation.png \
		plugins/content_types/block/icon_core_block_menu.png \
		plugins/content_types/block/icon_core_block_empty.png \
		plugins/content_types/block/icon_core_block.png \
		plugins/content_types/block/icon_core_authorinformation.png \
		plugins/content_types/block/icon_core_activeforumtopics.png \
		plugins/content_types/block/icon_contrib_page.png \
		plugins/content_types/block/icon_contrib_menu.png \
		plugins/content_types/block/icon_contrib_block_empty.png \
		plugins/content_types/block/icon_contrib_block.png \
		plugins/content_types/block/block.inc \
		plugins/arguments/vid.inc \
		plugins/arguments/user_name.inc \
		plugins/arguments/uid.inc \
		plugins/arguments/translations/plugins-arguments.hu.po \
		plugins/arguments/terms.inc \
		plugins/arguments/term.inc \
		plugins/arguments/string.inc \
		plugins/arguments/node_edit.inc \
		plugins/arguments/node_add.inc \
		plugins/arguments/nid.inc \
		plugins/access/translations/plugins-access.hu.po \
		plugins/access/theme.inc \
		plugins/access/term_vocabulary.inc \
		plugins/access/term_parent.inc \
		plugins/access/term.inc \
		plugins/access/string_length.inc \
		plugins/access/string_equal.inc \
		plugins/access/site_language.inc \
		plugins/access/role.inc \
		plugins/access/php.inc \
		plugins/access/perm.inc \
		plugins/access/path_visibility.inc \
		plugins/access/node_type.inc \
		plugins/access/node_language.inc \
		plugins/access/node_access.inc \
		plugins/access/node.inc \
		plugins/access/context_exists.inc \
		plugins/access/compare_users.inc \
		page_manager/translations/page_manager.pot \
		page_manager/translations/page_manager.hu.po \
		page_manager/translations/page_manager.fr.po \
		page_manager/translations/page_manager.de.po \
		page_manager/theme/translations/page_manager-theme.hu.po \
		page_manager/theme/page_manager.theme.inc \
		page_manager/theme/page-manager-edit-page.tpl.php \
		page_manager/plugins/tasks/user_view.inc \
		page_manager/plugins/tasks/translations/page_manager-plugins-tasks.hu.po \
		page_manager/plugins/tasks/term_view.inc \
		page_manager/plugins/tasks/search.inc \
		page_manager/plugins/tasks/poll.inc \
		page_manager/plugins/tasks/page.inc \
		page_manager/plugins/tasks/page.admin.inc \
		page_manager/plugins/tasks/node_view.inc \
		page_manager/plugins/tasks/node_edit.inc \
		page_manager/plugins/tasks/contact_user.inc \
		page_manager/plugins/tasks/contact_site.inc \
		page_manager/plugins/tasks/blog_user.inc \
		page_manager/plugins/tasks/blog.inc \
		page_manager/page_manager.module \
		page_manager/page_manager.install \
		page_manager/page_manager.info \
		page_manager/page_manager.admin.inc \
		page_manager/js/page-list.js \
		page_manager/images/locked.png \
		page_manager/images/locked-other.png \
		page_manager/images/arrow-active.png \
		page_manager/help/variants.html \
		page_manager/help/page_manager.help.ini \
		page_manager/help/page-task-type.html \
		page_manager/help/getting-started.html \
		page_manager/help/getting-started-page-list.html \
		page_manager/help/getting-started-members.html \
		page_manager/help/getting-started-custom-vocabulary.html \
		page_manager/help/getting-started-custom-nodes.html \
		page_manager/help/getting-started-create.html \
		page_manager/help/custom-pages.html \
		page_manager/help/custom-pages-menu.html \
		page_manager/help/custom-pages-arguments.html \
		page_manager/help/custom-pages-access.html \
		page_manager/help/api-task.html \
		page_manager/help/api-task-type.html \
		page_manager/help/api-task-handler.html \
		page_manager/help/about.html \
		page_manager/css/page-manager.css \
		js/stylizer.js \
		js/modal.js \
		js/mc.js \
		js/jump-menu.js \
		js/dropdown.js \
		js/dimensions.js \
		js/dependent.js \
		js/collapsible-div.js \
		js/ajax-responder.js \
		includes/wizard.theme.inc \
		includes/wizard.inc \
		includes/translations/includes.hu.po \
		includes/stylizer.theme.inc \
		includes/stylizer.inc \
		includes/plugins.inc \
		includes/object-cache.inc \
		includes/modal.inc \
		includes/menu.inc \
		includes/jump-menu.inc \
		includes/form.inc \
		includes/export.inc \
		includes/dropdown.theme.inc \
		includes/dependent.inc \
		includes/css.inc \
		includes/context.theme.inc \
		includes/context.menu.inc \
		includes/context.inc \
		includes/context-task-handler.inc \
		includes/context-admin.inc \
		includes/context-access-admin.inc \
		includes/content.theme.inc \
		includes/content.menu.inc \
		includes/content.inc \
		includes/collapsible.theme.inc \
		includes/cleanstring.inc \
		includes/ajax.inc \
		images/throbber.gif \
		images/status-active.gif \
		images/no-icon.png \
		images/icon-delete.png \
		images/icon-configure.png \
		images/icon-close-window.png \
		images/collapsible-expanded.png \
		images/collapsible-collapsed.png \
		help/wizard.html \
		help/plugins.html \
		help/plugins-implementing.html \
		help/plugins-creating.html \
		help/plugins-api.html \
		help/object-cache.html \
		help/form.html \
		help/export.html \
		help/ctools.help.ini \
		help/context.html \
		help/context-relationships.html \
		help/context-context.html \
		help/context-content.html \
		help/context-arguments.html \
		help/context-access.html \
		help/ajax.html \
		help/about.html \
		delegator/delegator.module \
		delegator/delegator.admin.inc \
		ctools_plugin_example/translations/ctools_plugin_example.hu.po \
		ctools_plugin_example/plugins/relationships/translations/ctools_plugin_example-plugins-relationships.hu.po \
		ctools_plugin_example/plugins/relationships/relcontext_from_simplecontext.inc \
		ctools_plugin_example/plugins/panels.pages.inc \
		ctools_plugin_example/plugins/contexts/translations/ctools_plugin_example-plugins-contexts.hu.po \
		ctools_plugin_example/plugins/contexts/simplecontext.inc \
		ctools_plugin_example/plugins/contexts/relcontext.inc \
		ctools_plugin_example/plugins/content_types/translations/ctools_plugin_example-plugins-content_types.hu.po \
		ctools_plugin_example/plugins/content_types/simplecontext_content_type.inc \
		ctools_plugin_example/plugins/content_types/relcontext_content_type.inc \
		ctools_plugin_example/plugins/content_types/no_context_content_type.inc \
		ctools_plugin_example/plugins/content_types/icon_example.png \
		ctools_plugin_example/plugins/arguments/translations/ctools_plugin_example-plugins-arguments.hu.po \
		ctools_plugin_example/plugins/arguments/simplecontext_arg.inc \
		ctools_plugin_example/plugins/access/translations/ctools_plugin_example-plugins-access.hu.po \
		ctools_plugin_example/plugins/access/example_role.inc \
		ctools_plugin_example/plugins/access/arg_length.inc \
		ctools_plugin_example/help/ctools_plugin_example.help.ini \
		ctools_plugin_example/help/Relationships--Letting-one-context-take-us-to-another.html \
		ctools_plugin_example/help/Module-setup-and-hooks.html \
		ctools_plugin_example/help/Context-plugins--Creating-a--context--from-an-argument.html \
		ctools_plugin_example/help/Content-Type-Plugins--Displaying-content-using-a-context.html \
		ctools_plugin_example/help/Chaos-Tools--CTools--Plugin-Examples.html \
		ctools_plugin_example/help/Argument-Plugins--Starting-at-the-beginning.html \
		ctools_plugin_example/help/Access-Plugins--Determining-access-and-visibility.html \
		ctools_plugin_example/ctools_plugin_example.pages_default.inc \
		ctools_plugin_example/ctools_plugin_example.module \
		ctools_plugin_example/ctools_plugin_example.info \
		ctools.module ctools.install ctools.info css/wizard.css css/stylizer.css \
		css/modal.css css/dropdown.css css/ctools.css css/context.css \
		css/collapsible-div.css \
		bulk_export/translations/bulk_export.pot \
		bulk_export/translations/bulk_export.hu.po \
		bulk_export/bulk_export.module \
		bulk_export/bulk_export.info \
		bulk_export/bulk_export.css \

DOC_DIRS=	ctools_plugin_example

DOC_FILES=	ctools_plugin_example/README.txt LICENSE.txt \
		CHANGELOG.txt API.txt

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/drupal5/bsd.drupal.mk"
.include <bsd.port.post.mk>
