# Created by: Sergei Kolobov <sergei@kolobov.com>

PORTNAME=	libtasn1
PORTVERSION=	4.17.0
CATEGORIES=	security
MASTER_SITES=	GNU \
		GNUPG/gnutls/${PORTNAME}

MAINTAINER=	novel@FreeBSD.org
COMMENT=	ASN.1 structure parser library

LICENSE=	LGPL21+ GPLv3
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe libtool pathfix pkgconfig compiler
USE_CSTD=	c99
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
CPE_VENDOR=	gnu

OPTIONS_DEFINE=	DOCS

TEST_TARGET=	check

DOCS=		AUTHORS NEWS README.md THANKS doc/TODO \
		doc/libtasn1.html doc/libtasn1.pdf doc/libtasn1.ps
INFO=		libtasn1

.include <bsd.port.pre.mk>

# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=252548
.if ${CHOSEN_COMPILER_TYPE} == clang && ${COMPILER_VERSION} >= 100
CFLAGS:=		${CFLAGS:C/-O[2-9]/-O1/g}
.endif

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
