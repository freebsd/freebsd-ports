# New ports collection makefile for:	drupal6-imce
# Date created:		10 feb 2010
# Whom:			Anderson Soares Ferreira <anderson@cnpm.embrapa.br>
#
# $FreeBSD$
#

PORTNAME=	imce
DISTVERSION=	6.x-1.3
CATEGORIES=	www
MASTER_SITES=	http://ftp.drupal.org/files/projects/

MAINTAINER=	anderson@cnpm.embrapa.br
COMMENT=	Drupal 6.x image/file uploader module

DRUPAL6_MODULE=	yes

MODULE_DIRS=	translations tpl js inc css

MODULE_FILES=	css/collapsed.png \
		css/expanded.png \
		css/folder-open.png \
		css/folder.png \
		css/imce-content.css \
		css/leaf.png \
		css/loading.gif \
		css/x-grippie.png \
		css/y-grippie.png \
		inc/admin.inc \
		inc/core_profiles.inc \
		inc/js.inc \
		inc/page.inc \
		inc/subdir.inc \
		imce.info \
		imce.install \
		imce.module \
		js/imce.js \
		js/imce_extras.js \
		js/imce_set_app.js \
		js/imce_set_inline.js \
		tpl/imce-content.tpl.php \
		tpl/imce-file-list.tpl.php \
		tpl/imce-page.tpl.php \
		translations/imce.pot \
		translations/cs.po \
		translations/es.po \
		translations/fi.po \
		translations/fr.po \
		translations/hu.po \
		translations/pt-br.po \
		translations/ja.po \
		translations/nl.po \
		translations/sv.po

DOC_FILES=	README.txt LICENSE.txt

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/drupal5/bsd.drupal.mk"
.include <bsd.port.post.mk>
