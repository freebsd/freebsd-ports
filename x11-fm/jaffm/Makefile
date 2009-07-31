# New ports collection makefile for:	jaffm
# Date Created:				2006-04-27
# Whom:					Shaun Amott <shaun@inerd.com>
#
# $FreeBSD$
#

PORTNAME=	jaffm
PORTVERSION=	1.4
PORTREVISION=	5
CATEGORIES=	x11-fm
MASTER_SITES=	http://binary.is/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A lightweight file manager inspired by MacOS Finder

USE_BZIP2=	yes
USE_WX=		2.4-2.6
ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's#^PREFIX=.*#PREFIX=${PREFIX}#' \
		-e 's#$$(shell wx-config \(.*\))#`${WX_CONFIG} \1`#' \
		-e 's#^FLAGS=-ggdb#FLAGS=${CFLAGS}#' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.post.mk>
