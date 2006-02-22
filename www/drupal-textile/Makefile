# New ports collection makefile for:	drupal-textile
# Date created:				21 February 2006
# Whom:					Brooks Davis <brooks@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	textile
DISTVERSION=	${DRUPAL_VERSION}
PORTREVISION=	20060210
CATEGORIES=	www textproc
MASTER_SITE_SUBDIR=	brooks

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	Textile markup module for Drupal

DRUPAL_MODULE=	yes
MODULE_DIRS=	textilephp
MODULE_FILES=	textile.module textilephp/Textile.php
DOC_DIRS=	textilephp/doc textilephp
DOC_FILES=	CHANGELOG.txt CREDITS.txt INSTALL.txt LICENSE.txt README.txt \
		textilephp/doc/classMTLikeTextile-members.html \
		textilephp/doc/Textile_8php-source.html \
		textilephp/doc/Textile_8php.html \
		textilephp/doc/annotated.html \
		textilephp/doc/classTextile-members.html \
		textilephp/doc/classMTLikeTextile.html \
		textilephp/doc/classMTLikeTextile.png \
		textilephp/doc/classTextile.html \
		textilephp/doc/classTextile.png \
		textilephp/doc/doxygen.css \
		textilephp/doc/doxygen.png \
		textilephp/doc/files.html \
		textilephp/doc/functions.html \
		textilephp/doc/functions_func.html \
		textilephp/doc/functions_vars.html \
		textilephp/doc/hierarchy.html \
		textilephp/doc/index.html \
		textilephp/textilephp.doxyfile \
		textilephp/CHANGELOG \
		textilephp/CREDITS \
		textilephp/README \
		textilephp/TODO

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/drupal/bsd.drupal.mk"
.include <bsd.port.post.mk>
