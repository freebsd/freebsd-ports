# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	engine_pkcs11
PORTVERSION=	0.1.8
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	SF/opensc/${PORTNAME}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Implementation of a PKCS\#11 engine for OpenSSL

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libp11.so:${PORTSDIR}/security/libp11

OPTIONS_DEFINE=	DOCS

USES=		libtool pkgconfig
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ENV=	OPENSSL_CFLAGS="-I${OPENSSLINC}" \
		OPENSSL_LIBS="-L${OPENSSLLIB} -lssl"

PORTDOCS=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
CONFIGURE_ARGS+=--enable-doc
.endif

.include <bsd.port.mk>
