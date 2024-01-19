PORTNAME=	deltup
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.6
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/jjwhitney/Deltup/archive/refs/tags/ \
		http://www.bzip.org/${BZIP2_102}/:bzip2102src \
		http://www.bzip.org/${BZIP2_103}/:bzip2103src
DISTFILES+=	${DISTVERSIONPREFIX}${DISTVERSION}.tar.gz \
		${BZIP2_102_SOURCE}:bzip2102src \
		${BZIP2_103_SOURCE}:bzip2103src

MAINTAINER=	se@FreeBSD.org
COMMENT=	Source delta update program
WWW=		https://github.com/jjwhitney/Deltup # http://www.deltup.org/

LICENSE=	GPLv2+

RUN_DEPENDS=	bdelta:misc/bdelta \
		gzip>=1:archivers/gzip \
		xdelta:misc/xdelta

BZIP2_102_SOURCE=	bzip2-${BZIP2_102}.tar.gz
BZIP2_103_SOURCE=	bzip2-${BZIP2_103}.tar.gz

BZIP2_102=	1.0.2
BZIP2_103=	1.0.3

USES=		gmake ssl
MAKE_ARGS=	CC="${CC}" \
		CXX="${CXX}" \
		PREFIX="${PREFIX}"
CXXFLAGS+=	-I${OPENSSLINC}

WRKSRC=			${WRKDIR}/Deltup-${PORTVERSION}
WRKSRC_BZIP2_102=	${WRKDIR}/bzip2-${BZIP2_102}
WRKSRC_BZIP2_103=	${WRKDIR}/bzip2-${BZIP2_103}

PLIST_FILES=	bin/bzip2_1.0.2 \
		bin/bzip2_1.0.3 \
		bin/deltup \
		share/man/man1/deltup.1.gz

PORTDOCS=	ChangeLog README

OPTIONS_DEFINE=	DOCS

pre-build:
	@${REINPLACE_CMD} -e 's,CC,CXX,;s,gcc,$${CXX},' \
		-e "s|\(-lcrypto\)|-L${OPENSSLLIB} \1|g" ${WRKSRC}/src/Makefile
	@${REINPLACE_CMD} -e 's|-Wall -Winline -O2|-Wall -Winline -O2 ${CFLAGS}|' \
		${WRKSRC_BZIP2_102}/Makefile
	@${REINPLACE_CMD} -e 's|-Wall -Winline -O -g|-Wall -Winline -O2 ${CFLAGS}|' \
		${WRKSRC_BZIP2_103}/Makefile

do-build:
	@cd ${WRKSRC_BZIP2_102} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} bzip2
	@cd ${WRKSRC_BZIP2_103} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} bzip2
	cd ${WRKSRC}/src && ${MAKE} deltup

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/deltup ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC_BZIP2_102}/bzip2 ${STAGEDIR}${PREFIX}/bin/bzip2_1.0.2
	${INSTALL_PROGRAM} ${WRKSRC_BZIP2_103}/bzip2 ${STAGEDIR}${PREFIX}/bin/bzip2_1.0.3
	${INSTALL_MAN} ${WRKSRC}/deltup.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}/${i}
.endfor

.include <bsd.port.mk>
