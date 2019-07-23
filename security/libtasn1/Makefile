# Created by: Sergei Kolobov <sergei@kolobov.com>
# $FreeBSD$

PORTNAME=	libtasn1
PORTVERSION=	4.14
CATEGORIES=	security
MASTER_SITES=	GNU \
		GNUPG/gnutls/${PORTNAME}

MAINTAINER=	novel@FreeBSD.org
COMMENT=	ASN.1 structure parser library

LICENSE=	LGPL21+ GPLv3
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe pkgconfig pathfix gmake libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
CPE_VENDOR=	gnu

OPTIONS_DEFINE=	DOCS

DOCS=		AUTHORS NEWS README.md THANKS doc/TODO \
		doc/libtasn1.html doc/libtasn1.pdf doc/libtasn1.ps
INFO=		libtasn1

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
