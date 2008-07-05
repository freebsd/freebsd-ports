# New ports collection makefile for:	drupal5-gsitemap
# Date created:				26 Mar 2007
# Whom:					Nick Hilliard <nick@foobar.org>
#
# $FreeBSD$
#

PORTNAME=	xmlsitemap
DISTVERSION=	5.x-1.6
CATEGORIES=	www
MASTER_SITES=	http://ftp.drupal.org/files/projects/

MAINTAINER=	nick@foobar.org
COMMENT=	Produces sitemaps.org compliant XML WWW site maps

DRUPAL5_MODULE=	yes

MODULE_DIRS=	xmlsitemap_user xmlsitemap_term xmlsitemap_engines \
		xmlsitemap_node gss docs

MODULE_FILES=	xmlsitemap.info xmlsitemap.module \
		xmlsitemap_user/xmlsitemap_user.install \
		xmlsitemap_user/xmlsitemap_user.info \
		xmlsitemap_user/xmlsitemap_user.module \
		xmlsitemap_term/xmlsitemap_term.module \
		xmlsitemap_term/xmlsitemap_term.install \
		xmlsitemap_term/xmlsitemap_term.info \
		xmlsitemap_engines/xmlsitemap_engines.install \
		xmlsitemap_engines/xmlsitemap_engines.module \
		xmlsitemap_engines/xmlsitemap_engines.info \
		xmlsitemap_node/xmlsitemap_node.install \
		xmlsitemap_node/xmlsitemap_node.module \
		xmlsitemap_node/xmlsitemap_node.info xmlsitemap.install \
		gss/sortdown.gif gss/gss.css gss/gss.js gss/gss.xsl \
		gss/sortup.gif docs/xmlsitemap.php

DOC_FILES=	CHANGELOG.txt INSTALL.txt LICENSE.txt README.txt

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/drupal5/bsd.drupal.mk"
.include <bsd.port.post.mk>
