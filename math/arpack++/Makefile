# New ports collection makefile for:	arpack++
# Date created:         17 October 2003
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	arpack++
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.ime.unicamp.br/%7echico/arpack++/
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ARPACK++ is an object-oriented version of the ARPACK package

RUN_DEPENDS=	${LOCALBASE}/lib/libarpack.a:${PORTSDIR}/math/arpack \
		${LOCALBASE}/lib/libf77blas.a:${PORTSDIR}/math/atlas \
		${LOCALBASE}/lib/liblapack.a:${PORTSDIR}/math/lapack \
		${LOCALBASE}/lib/libsuperlu.a:${PORTSDIR}/math/superlu \
		${LOCALBASE}/lib/libumfpack.a:${PORTSDIR}/math/umfpack \
		gmake:${PORTSDIR}/devel/gmake

NO_BUILD=	yes
USE_REINPLACE=	yes
REINPLACE_ARGS=	-i ""

DOCS=		README doc/arpackpp.ps.gz doc/bugs.txt doc/structure.txt

post-patch:
	@${RM} ${WRKSRC}/include/arlutil.h.orig
.if !defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|g"	\
		-e "s|%%PREFIX%%|${PREFIX}|" ${WRKSRC}/Makefile.inc
	@${FIND} ${WRKSRC}/examples -name Makefile |	\
	${XARGS} ${REINPLACE_CMD} -e "s|../../../Makefile.inc|../../Makefile.inc|" \
				-e 's|$$(ARPACKPP_DIR)/examples|${EXAMPLESDIR}|'
.endif

do-install:
	@${MKDIR} ${PREFIX}/include/ARPACK++
	@for inc in `${LS} ${WRKSRC}/include` ; do \
		${INSTALL_DATA} ${WRKSRC}/include/$$inc ${PREFIX}/include/ARPACK++; \
	done
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
	@${GUNZIP_CMD} ${DOCSDIR}/arpackpp.ps.gz
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/Makefile.inc ${EXAMPLESDIR}
	@${CP} -R ${WRKSRC}/examples/* ${EXAMPLESDIR}
	@${ECHO_MSG} "===> Examples installed in ${EXAMPLESDIR}."
.endif

.if defined(MAINTAINER_MODE)
test:	install
	for sample in `${FIND} ${EXAMPLESDIR} -name Makefile` ; do \
		(cd `dirname $$sample` ; \
		${ECHO_MSG} "============" ; \
		${ECHO_MSG} "*** Entering `pwd`" ; \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} \
		|| ${TRUE}) ; \
	done
	@${ECHO_MSG} "============"
	@${ECHO_MSG} "Failures expected in umfpack/complex, umfpack/nonsym & umfpack/sym"
	@${ECHO_MSG} "(UM*2FA -> umfpack_*_numeric)."
	@${ECHO_MSG}
.endif

.include <bsd.port.mk>
