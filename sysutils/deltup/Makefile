# Created by: Roman Bogorodskiy <novel@FreeBSD.org>
# $FreeBSD$

PORTNAME=	deltup
PORTVERSION=	0.4.4
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://deltup.org/e107_files/downloads/ \
		LOCAL/rafan \
		http://www.bzip.org/${BZIP2_102}/:bzip2102src \
		http://www.bzip.org/${BZIP2_103}/:bzip2103src
DISTFILES+=	${DISTNAME}.tar.gz ${BZIP2_102_SOURCE}:bzip2102src ${BZIP2_103_SOURCE}:bzip2103src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Source delta update program

RUN_DEPENDS=	bdelta:misc/bdelta \
		xdelta:misc/xdelta \
		gzip>=1:archivers/gzip

BZIP2_102_SOURCE=	bzip2-${BZIP2_102}.tar.gz
BZIP2_103_SOURCE=	bzip2-${BZIP2_103}.tar.gz

BZIP2_102=	1.0.2
BZIP2_103=	1.0.3

USES=		gmake ssl
ALL_TARGET=	deltup
MAKE_ARGS=	CC="${CC}" CXX="${CXX}" PREFIX="${PREFIX}"
CXXFLAGS+=	-I${OPENSSLINC}
PLIST_FILES=	bin/deltup \
		bin/bzip2_1.0.2 \
		bin/bzip2_1.0.3 \
		man/man1/deltup.1.gz
WRKSRC_BZIP2_102=	${WRKDIR}/bzip2-${BZIP2_102}
WRKSRC_BZIP2_103=	${WRKDIR}/bzip2-${BZIP2_103}

PORTDOCS=	ChangeLog README

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's/CC/CXX/' -e 's,gcc,$${CXX},' \
		-e "s|\(-lcrypto\)|-L${OPENSSLLIB} \1|g" ${WRKSRC}/Makefile

pre-build:
	@${REINPLACE_CMD} -e 's|-Wall -Winline -O2|-Wall -Winline -O2 ${CFLAGS}|' \
		${WRKSRC_BZIP2_102}/Makefile
	@${REINPLACE_CMD} -e 's|-Wall -Winline -O -g|-Wall -Winline -O2 ${CFLAGS}|' \
		${WRKSRC_BZIP2_103}/Makefile
	@(cd ${WRKSRC_BZIP2_102} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} bzip2)
	@(cd ${WRKSRC_BZIP2_103} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} bzip2)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/deltup ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC_BZIP2_102}/bzip2 ${STAGEDIR}${PREFIX}/bin/bzip2_1.0.2
	${INSTALL_PROGRAM} ${WRKSRC_BZIP2_103}/bzip2 ${STAGEDIR}${PREFIX}/bin/bzip2_1.0.3
	${INSTALL_MAN} ${WRKSRC}/deltup.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}/${i}
.endfor

.include <bsd.port.mk>
