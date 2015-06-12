# Created by: ijliao
# $FreeBSD$

PORTNAME=	fxt
PORTVERSION=	2012.06.18
CATEGORIES=	math
MASTER_SITES=	http://www.jjj.de/fxt/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FFT code and related stuff

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		gmake tar:tgz
MAKEFILE=	makefile

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's,^(FXT_CXXFLAGS),#\1,' \
		-e 's,^(CXXFLAGS),#\1,' \
		 ${WRKSRC}/makefile
	@${REINPLACE_CMD} -e 's|sinl|Sin|g' ${WRKSRC}/src/aux0/trigrec.h
	@${REINPLACE_CMD} -e 's|sinl|sin|g' ${WRKSRC}/src/fht/hartleyshift.h

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/00*.txt ${STAGEDIR}${DOCSDIR}/
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/demo && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR}/)

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

.include <bsd.port.mk>
