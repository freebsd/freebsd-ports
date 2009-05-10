# New ports collection makefile for:	drupal6-mimedetect
# Date created:		05 Feb,2009
# Whom:			Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	mimedetect
DISTVERSION=	6.x-1.2
CATEGORIES=	www
MASTER_SITES=	http://ftp.drupal.org/files/projects/

MAINTAINER=	wenheping@gmail.com
COMMENT=	An API for Consistent Server Side Mime Detection

DRUPAL6_MODULE=	yes

MODULE_FILES=	magic magic.mgc magic.mime \
		mimedetect.info mimedetect.install mimedetect.module
DOC_FILES=	LICENSE.txt README.txt

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/drupal5/bsd.drupal.mk"
.include <bsd.port.post.mk>
