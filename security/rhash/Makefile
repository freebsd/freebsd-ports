# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>

PORTNAME=	rhash
PORTVERSION=	1.4.3
CATEGORIES=	security
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Utility and library for computing and checking of file hashes

LICENSE=	BSD0CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix="${PREFIX}" --mandir="${PREFIX}/man" \
		--pkgconfigdir="${PREFIX}/libdata/pkgconfig" \
		--enable-lib-static --enable-openssl-runtime \
		--extra-cflags="${CFLAGS}" --extra-ldflags="${LDFLAGS}"
INSTALL_TARGET=	install install-lib-so-link install-pkg-config

USES=		cpe
CPE_VENDOR=	${PORTNAME}_project
USE_LDCONFIG=	yes

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

do-test:
	cd ${WRKSRC}/tests && ${SH} test_rhash.sh --full --shared

.include <bsd.port.mk>
