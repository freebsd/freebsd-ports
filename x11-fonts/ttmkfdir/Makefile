# New ports collection makefile for:	ttmkfdir
# Version required:	0.0
# Date created:		September 08, 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id: Makefile,v 1.2 1998/09/21 08:41:45 asami Exp $

DISTNAME=	ttmkfdir
PKGNAME=	ttmkfdir-0.0
CATEGORIES=	x11
MASTER_SITES=	http://www.darmstadt.gmd.de/~pommnitz/

MAINTAINER=	ports@FreeBSD.ORG

LIB_DEPENDS=	ttf.3:${PORTSDIR}/print/freetype

NO_WRKSUBDIR=	yes
USE_X_PREFIX=	yes

do-build:
	cd ${WRKSRC}; \
	${CC} ${CFLAGS} -I${LOCALBASE}/include ttmkfdir.c -o ttmkfdir -L${LOCALBASE}/lib -lttf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ttmkfdir ${PREFIX}/bin

.include <bsd.port.mk>
