# New ports collection makefile for:	ttmkfdir
# Version required:	0.0
# Date created:		September 08, 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$

DISTNAME=	ttmkfdir
PKGNAME=	ttmkfdir-0.0
CATEGORIES=	x11
MASTER_SITES=	http://www.darmstadt.gmd.de/~pommnitz/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	ttf.4:${PORTSDIR}/print/freetype

NO_WRKSUBDIR=	yes
USE_X_PREFIX=	yes

do-build:
	cd ${WRKSRC}; \
	${CC} ${CFLAGS} -I${LOCALBASE}/include ttmkfdir.c -o ttmkfdir -L${LOCALBASE}/lib -lttf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ttmkfdir ${PREFIX}/bin

.include <bsd.port.mk>
