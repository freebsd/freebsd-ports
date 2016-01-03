# Created by: janos.mohacsi@bsd.hu
# $FreeBSD$

PORTNAME=	mgen
PORTVERSION=	4.2b6
CATEGORIES=	net
MASTER_SITES=	http://downloads.pf.itd.nrl.navy.mil/mgen/archive/mgen4/ \
		LOCAL/miwi
DISTNAME=	src-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IP network performance tests and measurements

# Dumps core on 64-bit architectures. This was reported to the upstream
# author, who promised to fix it in one of the next releases.
ONLY_FOR_ARCHS=	i386
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		gmake tar:tgz
MAKEFILE=	Makefile.freebsd
BUILD_WRKSRC=	${WRKSRC}/unix
ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/mgen
PORTDOCS=	README.TXT VERSION.TXT mgen.html example.mgn

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|g++|${CXX}|; s|gcc|${CC}|; \
		/CFLAGS =/s|$$|${CFLAGS}|' \
		${WRKSRC}/unix/Makefile.freebsd \
		${WRKSRC}/protolib/unix/Makefile.freebsd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unix/mgen ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for FILE in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
