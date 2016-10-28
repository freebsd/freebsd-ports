# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rhash
PORTVERSION=	1.3.3
CATEGORIES=	security
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Utility and library for computing and checking of file hashes

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PORTDOCS=	ChangeLog README

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's,/etc/,${PREFIX}&,' ${WRKSRC}/parse_cmdline.c
	@${REINPLACE_CMD} -e '/BYTE_ORDER/s,__,_,g' \
		${WRKSRC}/librhash/byte_order.h

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/rhash \
		${STAGEDIR}${PREFIX}/lib/librhash.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

do-test:
	cd ${WRKSRC}/tests && ${SH} test_rhash.sh --full

.include <bsd.port.mk>
