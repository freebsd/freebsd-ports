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
MASTER_SITES=	${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=	pool/main/s/${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	vs@FreeBSD.org
COMMENT=	Shows X-Faces from slrn in X11 terminal emulator

LIB_DEPENDS=	compface:${PORTSDIR}/mail/faces

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
ALL_TARGET=	slrnface
MAKE_ARGS=	CC="${CC}" C_FLAGS="${CFLAGS}" \
		X_INCL=-I${X11BASE}/include \
		XF_LIB="-L${X11BASE}/lib -L${LOCALBASE}/lib -lcompface"

USE_XLIB=	yes

MAN1=		slrnface.1
PLIST_FILES=	bin/slrnface share/examples/slrnface/slrnface.sl
PLIST_DIRS=	share/examples/slrnface

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/slrnface ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/slrnface.1 ${MAN1PREFIX}/man/man1/slrnface.1
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/slrnface.sl ${EXAMPLESDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
