# New ports collection makefile for:	pkcs11-helper
# Date created:			8 Jan 2007
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pkcs11-helper
PORTVERSION=	1.08
CATEGORIES=	security devel
MASTER_SITES=	http://www.opensc-project.org/files/${PORTNAME}/

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A helper library for multiple PKCS\#11 providers

LICENSE=	BSD GPLv2
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_FILE_BSD=	${WRKSRC}/COPYING.BSD
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING.GPL

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
	@${REINPLACE_CMD} 's|install-data-am: install-apidocDATA|install-data-am:|' \
		${WRKSRC}/doc/api/Makefile.in
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} 's|install-data-am: install-dist_docDATA|install-data-am:|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} 's|install-data-am: install-man install-nodist_htmlDATA|install-data-am: install-man|' \
		${WRKSRC}/man/Makefile.in
.endif

.include <bsd.port.mk>
