# New ports collection makefile for:	wmwork
# Date created:			16 May 2002
# Whom:				Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	wmwork
PORTVERSION=	0.2.4
PORTREVISION=	1
CATEGORIES=	misc windowmaker afterstep
MASTER_SITES=	http://www.godisch.de/debian/wmwork/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A dockapp that keeps track of time you have spent on something

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GETOPT_LONG=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS}"

MAN1=		wmwork.1
PLIST_FILES=	bin/wmwork

CFLAGS+=	-I${X11BASE}/include -I${LOCALBASE}/include
LDFLAGS=	-L${X11BASE}/lib

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/wmwork ${PREFIX}/bin/wmwork
	@${INSTALL_MAN} ${WRKSRC}/wmwork.1 ${MANPREFIX}/man/man1/

.include <bsd.port.mk>
