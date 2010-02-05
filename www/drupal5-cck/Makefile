# New ports collection makefile for:  drupal5-cck
# Date created:  11 February 2008
# Whom:          Jeremy Iverson <jeremy@algenta.com>
#
# $FreeBSD$
#

PORTNAME=	cck
DISTVERSION=	5.x-1.6-1
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://ftp.drupal.org/files/projects/

MAINTAINER=	jeremy@algenta.com
COMMENT=	Content Construction Kit (CCK) module for Drupal 5

DRUPAL5_MODULE=	yes
MODULE_DIRS=	po theme
MODULE_FILES=	content.css content.info content.install content.module content_admin.css \
		content_admin.inc content_copy.info content_copy.module content_crud.inc \
		content_pathauto.inc content_views.inc \
		field.php fieldgroup.css fieldgroup.info fieldgroup.install fieldgroup.module \
		nodereference.info nodereference.install nodereference.module \
		number.info number.install number.module \
		optionwidgets.info optionwidgets.install optionwidgets.module \
		po/cck.pot po/de.po po/es.po po/fr.po po/nl.po po/pt.po po/ru.po po/vi.po \
		text.info text.install text.module \
		theme/README.txt theme/field-field_my_field.tpl.php theme/field.tpl.php \
		theme/node-content_example.tpl.php theme/template.php \
		userreference.info userreference.install userreference.module
DOC_FILES=	CHANGELOG.txt LICENSE.txt README.txt UPGRADE.txt

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/drupal5/bsd.drupal.mk"
.include <bsd.port.post.mk>
