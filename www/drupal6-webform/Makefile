# Created by: Nick Hilliard <nick@foobar.org>
# $FreeBSD$

PORTNAME=	webform
DISTVERSION=	6.x-3.17
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Drupal module to allow easy creation of forms

USES=		drupal:6,module

MODULE_FILES=	components/date.inc \
		components/email.inc \
		components/fieldset.inc \
		components/file.inc \
		components/grid.inc \
		components/hidden.inc \
		components/markup.inc \
		components/number.inc \
		components/pagebreak.inc \
		components/select.inc \
		components/textarea.inc \
		components/textfield.inc \
		components/time.inc \
		css/webform-admin.css \
		css/webform.css \
		images/calendar.png \
		includes/webform.admin.inc \
		includes/webform.components.inc \
		includes/webform.emails.inc \
		includes/webform.export.inc \
		includes/webform.options.inc \
		includes/webform.pages.inc \
		includes/webform.report.inc \
		includes/webform.submissions.inc \
		js/select-admin.js \
		js/webform-admin.js \
		js/webform.js \
		templates/webform-calendar.tpl.php \
		templates/webform-confirmation.tpl.php \
		templates/webform-form.tpl.php \
		templates/webform-mail.tpl.php \
		templates/webform-results-submissions.tpl.php \
		templates/webform-submission-information.tpl.php \
		templates/webform-submission-navigation.tpl.php \
		templates/webform-submission-page.tpl.php \
		templates/webform-submission.tpl.php \
		tests/components.test \
		tests/permissions.test \
		tests/submission.test \
		tests/webform.test \
		views/webform.views.inc \
		views/webform_handler_field_form_body.inc \
		views/webform_handler_field_is_draft.inc \
		views/webform_handler_field_node_link_edit.inc \
		views/webform_handler_field_node_link_results.inc \
		views/webform_handler_field_submission_count.inc \
		views/webform_handler_field_submission_link.inc \
		views/webform_handler_filter_is_draft.inc \
		webform.api.php \
		webform.info \
		webform.install \
		webform.module

MODULE_DIRS=	components \
		css \
		images \
		includes \
		js \
		templates \
		tests \
		views

DOC_FILES=	CHANGELOG.txt LICENSE.txt README.txt THEMING.txt
OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
