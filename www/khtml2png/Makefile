# New ports collection makefile for:	www/khtml2png
# Date created:				Nov 27 2007
# Whom:                			Rong-En Fan <rafan@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	khtml2png
DISTVERSION=	2.7.6
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}2/${PORTVERSION}

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	Command line program to create screenshots of webpages

USE_KDELIBS_VER=	3
USE_CMAKE=		yes

PLIST_FILES=	bin/khtml2png2

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,QT_QT_LIBRARY,QT_LIBRARIES,g' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.post.mk>
