# ex:ts=8
# Ports collection makefile for:	flu
# Date created:			Aug 23, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	flu
PORTVERSION=	2.13
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://www.osc.edu/~jbryan/FLU/
DISTNAME=	${PORTNAME:U}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A small collection of FLTK Widgets

LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk

USE_X_PREFIX=	yes
USE_GL=		yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --I=${X11BASE}/include --L=${X11BASE}/lib
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

PLIST_FILES=	bin/flu-config lib/libflu.so.${PORTVERSION} \
		lib/libflu_gl.so.${PORTVERSION}

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

post-install:
	${LN} -fs ${PREFIX}/lib/libflu.so.${PORTVERSION} ${PREFIX}/lib/libflu.so.2
	${LN} -fs ${PREFIX}/lib/libflu_gl.so.${PORTVERSION} ${PREFIX}/lib/libflu_gl.so.2
	@${FIND} ${PREFIX}/include/FLU ! -type d | \
		${SED} "s,^${PREFIX}/,," >> ${TMPPLIST}
	@${FIND} ${PREFIX}/include/FLU -type d | ${SORT} -r | \
		${SED} "s,^${PREFIX}/,@dirrm ," >> ${TMPPLIST}
	@${ECHO_CMD} "@exec ln -fs %D/lib/libflu.so.${PORTVERSION} %D/lib/libflu.so.2" >> ${TMPPLIST}
	@${ECHO_CMD} "@exec ln -fs %D/lib/libflu_gl.so.${PORTVERSION} %D/lib/libflu.so.2" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec rm -f %D/lib/libflu.so.2 %D/lib/libflu_gl.so.2 2>/dev/null || true" >> ${TMPPLIST}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/ ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/ ${EXAMPLESDIR}
	@${FIND} ${EXAMPLESDIR} ! -type d | \
		${SED} "s,^${PREFIX}/,," >> ${TMPPLIST}
	@${FIND} ${EXAMPLESDIR} -type d | ${SORT} -r | \
		${SED} "s,^${PREFIX}/,@dirrm ," >> ${TMPPLIST}
.endif

.include <bsd.port.mk>
