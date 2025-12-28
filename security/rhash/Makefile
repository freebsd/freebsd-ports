PORTNAME=	rhash
PORTVERSION=	1.4.4
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

PATCH_SITES=	https://github.com/rhash/RHash/commit/
PATCHFILES+=	c804982d1b24c6533118b3068d2cfdca685076f3.patch:-p1
PATCHFILES+=	9ef90b958b7ae50aeeb5c269468034d73d6e2efe.patch:-p1
PATCHFILES+=	b8c91ea6551e99e10352386cd46ea26973bb4a4d.patch:-p1

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Utility and library for computing and checking of file hashes
WWW=		https://rhash.sourceforge.io/

LICENSE=	BSD0CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe
CPE_VENDOR=	${PORTNAME}_project
USE_LDCONFIG=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix="${PREFIX}" \
		--pkgconfigdir="${PREFIX}/libdata/pkgconfig" \
		--enable-lib-static --enable-openssl-runtime \
		--extra-cflags="${CFLAGS}" --extra-ldflags="${LDFLAGS}"
MAKE_ARGS=	INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_SHARED="${INSTALL_LIB}"
INSTALL_TARGET=	install install-lib-so-link install-pkg-config
TEST_TARGET=	test-full

WRKSRC=		${WRKDIR}/RHash-${PORTVERSION}

PORTDOCS=	ChangeLog README.md

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext localbase:ldflags
NLS_CONFIGURE_ON=	--enable-gettext
NLS_INSTALL_TARGET=	install-gmo

post-patch:
	@${REINPLACE_CMD} -e '/BYTE_ORDER/s,__,_,g' \
		${WRKSRC}/librhash/byte_order.h

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
