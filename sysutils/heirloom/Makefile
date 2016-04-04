# Created by: Cyrille Lefevre <Cyrille.Lefevre@laposte.net>
# $FreeBSD$

PORTNAME=	heirloom
PORTVERSION=	070715
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Collection of standard Unix utilities

BUILD_DEPENDS=	ksh:shells/pdksh
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		gmake tar:bzip2
MAKE_ARGS=	CC=${CC} CFLAGS="${CFLAGS}" ROOT="${STAGEDIR}"
MAKEFILE=	makefile
ALL_TARGET=	#
DATADIR=	${PREFIX}/${PORTNAME}
REINPLACE_SUB=	DATADIR="${DATADIR}"

OPTIONS_DEFINE=	DOCS

SH2FIX=		maninst.sh genintro.sh crossln.sh

DOC_FILES=	CHANGES LICENSE/COPYING LICENSE/LICENSE LICENSE/LUCENT \
		LICENSE/README LICENSE/COPYING.LGPL README intro.txt

post-patch:
# FreeBSD does not have neither <malloc.h> nor <alloca.h> system headers
	@${GREP} -ERl --null 'm?alloca?\.h' ${WRKSRC} | \
		${XARGS} -0 ${REINPLACE_CMD} -E '/<m?alloca?\.h>/d'
# Avoid a race (to unbreak parallel builds)
	@${REINPLACE_CMD} -e 's|htemp2|$$@.temp|g' \
		${WRKSRC}/spell/Makefile.mk

pre-configure:
	@${REINPLACE_CMD} ${REINPLACE_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${WRKSRC}/build/mk.config ${WRKSRC}/su/su.dfl.in
	@${REINPLACE_CMD} -e 's|/sbin/sh| ${SH}|' \
		${SH2FIX:S|^|${WRKSRC}/build/|}

# XXX: hack to avoid inner race (for -jX builds); should be fixed properly
# one day (e.g. by factoring out special target in the top makefile)
pre-build:
	${MAKE_CMD} -C ${WRKSRC}/libcommon -f Makefile.mk headers

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/LICENSE
.for f in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/${f}
.endfor

.include <bsd.port.mk>
