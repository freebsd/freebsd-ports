# New ports collection makefile for:	wmwork
# Date created:			16 May 2002
# Whom:				Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	wmwork
PORTVERSION=	0.2.5
PORTREVISION=	2
CATEGORIES=	misc windowmaker afterstep
MASTER_SITES=	http://www.godisch.de/debian/wmwork/

MAINTAINER=	xride@FreeBSD.org
COMMENT=	A dockapp that keeps track of time you have spent on something

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

USE_XORG=	xpm
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		wmwork.1
PLIST_FILES=	bin/wmwork

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmwork ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wmwork.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
