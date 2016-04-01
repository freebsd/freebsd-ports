# Created by: arved
# $FreeBSD$

PORTNAME=	nxproxy
DISTVERSION=	3.5.0.32
CATEGORIES=	net
MASTER_SITES=	http://code.x2go.org/releases/source/nx-libs/
DISTNAME=	nx-libs-${PORTVERSION}-lite

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Helper program for x2go

LICENSE=	GPLv2

LIB_DEPENDS=	libXcomp.so:x11/nxcomp
WRKSRC=	${WRKDIR}/nx-libs-${PORTVERSION}/${PORTNAME}
LDFLAGS+=	-L${LOCALBASE}/lib

USES=		autoreconf
GNU_CONFIGURE=	yes
PLIST_FILES=	bin/nxproxy \
		man/man1/nxproxy.1.gz

.include <bsd.port.mk>
