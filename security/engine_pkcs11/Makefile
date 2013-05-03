# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	engine_pkcs11
PORTVERSION=	0.1.8
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.opensc-project.org/files/${PORTNAME}/

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Implementation of a PKCS\#11 engine for OpenSSL

LIB_DEPENDS=	p11.2:${PORTSDIR}/security/libp11

USE_AUTOTOOLS=	libtool
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
USES=		pkgconfig
.if defined(.PARSEDIR)
USE_GMAKE=	yes
.endif

CONFIGURE_ENV=	OPENSSL_CFLAGS="-I${OPENSSLINC}" \
		OPENSSL_LIBS="-L${OPENSSLLIB} -lssl"

PORTDOCS=	*

.ifndef(NOPORTDOCS)
CONFIGURE_ARGS+=--enable-doc
.else
post-patch:
	@${REINPLACE_CMD} 's|install-data-am: install-dist_docDATA|install-data-am:|' \
		${WRKSRC}/Makefile.in ${WRKSRC}/doc/Makefile.in
.endif

.include <bsd.port.mk>
