# New ports collection makefile for:   slrnface
# Date created:        10 April 2002
# Whom:                Oliver Braun <obraun@informatik.unibw-muenchen.de>
#
# $FreeBSD$
#

PORTNAME=	slrnface
PORTVERSION=	2.1.1
PORTREVISION=	1
CATEGORIES=	news
MASTER_SITES=	http://dave.willfork.com/slrnface/

MAINTAINER=	stolz@i2.informatik.rwth-aachen.de
COMMENT=	Shows X-Faces from slrn in X11 terminal emulator

LIB_DEPENDS=	compface:${PORTSDIR}/mail/faces

ALL_TARGET=	slrnface

USE_XLIB=	yes

MAN1=		slrnface.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/slrnface ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/slrnface.1 ${MAN1PREFIX}/man/man1/slrnface.1
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/slrnface.sl ${EXAMPLESDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
