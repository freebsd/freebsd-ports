PORTNAME=	nxproxy
DISTVERSION=	3.5.99.20
PORTREVISION=	1
DISTVERSIONSUFFIX=	-1
CATEGORIES=	net
MASTER_SITES=	https://code.x2go.org/releases/source/nx-libs/
DISTNAME=	nx-libs-${PORTVERSION}${DISTVERSIONSUFFIX}-lite

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Helper program for x2go
WWW=		https://wiki.x2go.org/doku.php

LICENSE=	GPLv2

LIB_DEPENDS=	libXcomp.so:x11/nxcomp

USES=		autoreconf localbase:ldflags
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

WRKSRC=		${WRKDIR}/nx-libs-${PORTVERSION}${DISTVERSIONSUFFIX}/${PORTNAME}

PLIST_FILES=	bin/nxproxy \
		share/man/man1/nxproxy.1.gz

.include <bsd.port.mk>
