# New ports collection makefile for:	engine_pkcs11
# Date created:			1 Jun 2006
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	engine_pkcs11
PORTVERSION=	0.1.6
CATEGORIES=	security
MASTER_SITES=	http://www.opensc-project.org/files/${PORTNAME}/

MAINTAINER=	ale@FreeBSD.org
COMMENT=	An implementation of a PKCS\#11 engine for OpenSSL

LIB_DEPENDS=	p11.3:${PORTSDIR}/security/libp11

USE_AUTOTOOLS=	libtool:15
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	pkgconfig

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
