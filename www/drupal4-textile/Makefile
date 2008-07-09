# New ports collection makefile for:	drupal-textile
# Date created:				21 February 2006
# Whom:					Brooks Davis <brooks@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	textile
DISTVERSION=	4.7.x-1.x-dev
PORTREVISION=	20061114
PORTEPOCH=	1
CATEGORIES=	www textproc
MASTER_SITE_SUBDIR=	brooks

MAINTAINER=	nick@foobar.org
COMMENT=	Textile markup module for Drupal

DRUPAL4_MODULE=	yes
MODULE_DIRS=	textilephp
MODULE_FILES=	textile.module textilephp/Textile.php DrupalTextile.inc
DOC_DIRS=	textilephp/doc textilephp
DOC_FILES=	CHANGELOG.txt CREDITS.txt INSTALL.txt LICENSE.txt README.txt \
		TODO.txt \
		textilephp/doc/Textile_8php-source.html \
		textilephp/doc/Textile_8php.html \
		textilephp/doc/annotated.html \
		textilephp/doc/classMTLikeTextile-members.html \
		textilephp/doc/classMTLikeTextile.html \
		textilephp/doc/classMTLikeTextile.png \
		textilephp/doc/classTextile-members.html \
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
		textilephp/LICENSE \
		textilephp/README \
		textilephp/TODO

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/drupal5/bsd.drupal.mk"
.include <bsd.port.post.mk>
