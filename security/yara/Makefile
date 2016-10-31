# $FreeBSD$

PORTNAME=	yara
PORTVERSION=	3.5.0
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Malware identification and classification tool

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	VirusTotal

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		alias autoreconf libtool pathfix ssl
USE_LDCONFIG=	yes
CPPFLAGS+=	-isystem ${OPENSSLINC}
LIBS+=		-L${OPENSSLLIB}

.include <bsd.port.mk>
