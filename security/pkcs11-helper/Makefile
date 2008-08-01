# New ports collection makefile for:	pkcs11-helper
# Date created:			8 Jan 2007
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pkcs11-helper
PORTVERSION=	1.06
CATEGORIES=	security devel
MASTER_SITES=	http://www.opensc-project.org/files/${PORTNAME}/

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A helper library for multiple PKCS\#11 providers

USE_BZIP2=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack pkgconfig
USE_LDCONFIG=	yes

CONFIGURE_ENV=	OPENSSL_CFLAGS="-I${OPENSSLINC}" \
		OPENSSL_LIBS="-L${OPENSSLLIB} -lssl"

CONFIGURE_ARGS=	--disable-crypto-engine-gnutls \
		--disable-crypto-engine-nss

MAN8=		pkcs11-helper-1.8

PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} 's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|' \
		${WRKSRC}/configure
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} 's|install-data-am: install-dist_docDATA|install-data-am|' \
		${WRKSRC}/Makefile.in
.endif


.include <bsd.port.mk>
