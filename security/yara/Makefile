# $FreeBSD$

PORTNAME=	yara
DISTVERSION=	4.0.2
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Malware identification and classification tool

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libjansson.so:devel/jansson

USE_GITHUB=	yes
GH_ACCOUNT=	VirusTotal

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-cuckoo --enable-dex --enable-dotnet --enable-macho --enable-magic
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
USES=		alias autoreconf libtool localbase pathfix pkgconfig ssl
USE_LDCONFIG=	yes
CPPFLAGS+=	-isystem ${OPENSSLINC}
LIBS+=		-L${OPENSSLLIB}

.include <bsd.port.mk>
