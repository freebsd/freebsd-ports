# Created by: arved
# $FreeBSD$

PORTNAME=	nxproxy
DISTVERSION=	3.5.0.33
CATEGORIES=	net
MASTER_SITES=	https://code.x2go.org/releases/source/nx-libs/
DISTNAME=	nx-libs-${PORTVERSION}-lite

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Helper program for x2go

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libXcomp.so:x11/nxcomp

USES=		autoreconf localbase:ldflags
GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/nx-libs-${PORTVERSION}/${PORTNAME}

PLIST_FILES=	bin/nxproxy \
		man/man1/nxproxy.1.gz

.include <bsd.port.mk>
