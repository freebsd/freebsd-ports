# Created by: arved
# $FreeBSD$

PORTNAME=	nxproxy
DISTVERSION=	3.5.0.27
CATEGORIES=	net
MASTER_SITES=	http://code.x2go.org/releases/source/nx-libs/
DISTNAME=	nx-libs-${PORTVERSION}-lite

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Helper program for x2go

LICENSE=	GPLv2

LIB_DEPENDS=	libXcomp.so:${PORTSDIR}/x11/nxcomp
WRKSRC=	${WRKDIR}/nx-libs-${PORTVERSION}/${PORTNAME}
LDFLAGS+=	-L${LOCALBASE}/lib

USE_AUTOTOOLS=	autoconf
PLIST_FILES=	bin/nxproxy \
		man/man1/nxproxy.1.gz

.include <bsd.port.mk>
