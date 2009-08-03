# New ports collection makefile for:	fxt
# Date created:			Nov 28, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	fxt
PORTVERSION=	2009.08.02
CATEGORIES=	math
MASTER_SITES=	http://www.jjj.de/fxt/
EXTRACT_SUFX=	.tgz

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	FFT code and related stuff

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_GMAKE=	yes
MAKEFILE=	makefile

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's,^(FXT_CXXFLAGS),#\1,' \
		-e 's,^(CXXFLAGS),#\1,' \
		 ${WRKSRC}/makefile
	@${REINPLACE_CMD} -e 's|sinl|Sin|g' ${WRKSRC}/src/aux0/trigrec.h
	@${REINPLACE_CMD} -e 's|sinl|sin|g' ${WRKSRC}/src/fht/hartleyshift.h

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/00*.txt ${DOCSDIR}/
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/demo && ${COPYTREE_SHARE} \* ${EXAMPLESDIR}/)
.endif

plist:
	@truncate -s0 pkg-plist
	@${ECHO_CMD} "lib/libfxt.a" >> pkg-plist

#
# Includes
#
	@${FIND} ${PREFIX}/include/fxt/ ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> pkg-plist
	@${FIND} ${PREFIX}/include/fxt/ -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> pkg-plist

#
# Examples
#
	@${FIND} ${EXAMPLESDIR}/ ! -type d | \
		${SED} 's,^${EXAMPLESDIR},%%PORTDOCS%%%%EXAMPLESDIR%%,' \
		>> pkg-plist
	@${FIND} ${EXAMPLESDIR}/ -type d | ${SORT} -r | \
		${SED} -E -e \
		's,^${EXAMPLESDIR}(.*),%%PORTDOCS%%@dirrm %%EXAMPLESDIR%%\1,' \
		>> pkg-plist

#
# Docs
#
	@${FIND} ${DOCSDIR}/ ! -type d | \
		${SED} 's,^${DOCSDIR},%%PORTDOCS%%%%DOCSDIR%%,' >> pkg-plist
	@${FIND} ${DOCSDIR}/ -type d | ${SORT} -r | \
		${SED} -E -e \
		's,^${DOCSDIR}(.*),%%PORTDOCS%%@dirrm %%DOCSDIR%%\1,' \
		>> pkg-plist

.include <bsd.port.post.mk>
