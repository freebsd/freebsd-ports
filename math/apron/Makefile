# $FreeBSD$

PORTNAME=	apron
DISTVERSION=	0.9.11
DISTVERSIONSUFFIX=	.r${SVN_REVISION}
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	APRON numerical abstract domain library

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

FETCH_DEPENDS=	svn:devel/subversion
LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr \
		libppl.so:devel/ppl

USES=		gmake localbase:ldflags
USE_LDCONFIG=	yes

SVN_URL=	svn://scm.gforge.inria.fr/svnroot/apron/apron/trunk
SVN_REVISION=	1104

do-fetch:
	@if [ "${FORCE_FETCH_ALL}" = "true" ] || ! [ -f "${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX}" ]; then \
	  ${MKDIR} ${DISTDIR}/${DIST_SUBDIR} && \
	  cd ${DISTDIR}/${DIST_SUBDIR} && \
	    svn co -r ${SVN_REVISION} ${SVN_URL} ${PORTNAME}-${DISTVERSIONFULL} && \
	    (cd ${PORTNAME}-${DISTVERSIONFULL} && ${RM} -r .svn) && \
	    ${FIND} ${PORTNAME}-${DISTVERSIONFULL} -and -exec ${TOUCH} -h -d 1970-01-01T00:00:00Z {} \; && \
	    ${FIND} ${PORTNAME}-${DISTVERSIONFULL} -print0 | LC_ALL=C ${SORT} -z | \
	        ${TAR} czf ${PORTNAME}-${DISTVERSIONFULL}${EXTRACT_SUFX} --format=bsdtar --gid 0 --uid 0 --options gzip:!timestamp --no-recursion --null -T - && \
	    ${RM} -r ${PORTNAME}-${DISTVERSIONFULL}; \
	fi

pre-build:
	@${CP} ${WRKSRC}/Makefile.config.model ${WRKSRC}/Makefile.config
	@${REINPLACE_CMD} -e ' \
		s|^APRON_PREFIX *=.*$$|APRON_PREFIX=${STAGEDIR}${LOCALBASE}|; \
		s|^HAS_OCAML *=.*$$|HAS_OCAML=|; \
		s|^HAS_OCAMLOPT *=.*$$|HAS_OCAMLOPT=|; \
		s|^OCAMLFIND *=.*$$|OCAMLFIND=|; \
		s|^# HAS_PPL *=.*$$|HAS_PPL=1|' \
		${WRKSRC}/Makefile.config

post-stage:
	  @${RM} ${STAGEDIR}${LOCALBASE}/bin/*test*
	  @${RM} ${STAGEDIR}${LOCALBASE}/lib/*.a
	  @${STRIP_CMD} ${STAGEDIR}${LOCALBASE}/lib/lib*.so

.include <bsd.port.mk>
