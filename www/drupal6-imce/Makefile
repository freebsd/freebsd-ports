# New ports collection makefile for:	drupal6-imce
# Date created:		10 feb 2010
# Whom:			Anderson Soares Ferreira <anderson@cnpm.embrapa.br>
#
# $FreeBSD$
#

PORTNAME=	imce
DISTVERSION=	6.x-1.4
CATEGORIES=	www
MASTER_SITES=	http://ftp.drupal.org/files/projects/

MAINTAINER=	anderson@cnpm.embrapa.br
COMMENT=	Drupal 6.x image/file uploader module

DRUPAL6_MODULE=	yes

MODULE_DIRS=	translations tpl js inc css

MODULE_FILES=	translations/uk.po \
		translations/uk-ua.po \
		translations/sv.po \
		translations/pt-br.po \
		translations/nl.po \
		translations/ja.po \
		translations/imce.pot \
		translations/hu.po \
		translations/fr.po \
		translations/fi.po \
		translations/es.po \
		translations/cs.po \
		tpl/imce-page.tpl.php \
		tpl/imce-file-list.tpl.php \
		tpl/imce-content.tpl.php \
		js/imce_set_inline.js \
		js/imce_set_app.js \
		js/imce_extras.js \
		js/imce.js \
		inc/subdir.inc \
		inc/page.inc \
		inc/js.inc \
		inc/core_profiles.inc \
		inc/admin.inc \
		imce.module \
		imce.install \
		imce.info \
		css/y-grippie.png \
		css/x-grippie.png \
		css/loading.gif \
		css/leaf.png \
		css/imce-content.css \
		css/folder.png \
		css/folder-open.png \
		css/expanded.png \
		css/collapsed.png

DOC_FILES=	README.txt LICENSE.txt

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/drupal5/bsd.drupal.mk"
.include <bsd.port.post.mk>
