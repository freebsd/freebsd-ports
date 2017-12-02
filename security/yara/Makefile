# $FreeBSD$

PORTNAME=	yara
PORTVERSION=	3.7.0
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Malware identification and classification tool

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	VirusTotal

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-magic --enable-dotnet
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
USES=		alias autoreconf libtool pathfix ssl
USE_LDCONFIG=	yes
CPPFLAGS+=	-isystem ${OPENSSLINC}
LIBS+=		-L${OPENSSLLIB}

.include <bsd.port.mk>
