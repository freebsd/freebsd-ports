# New ports collection makefile for:	isaac-cfd
# Date created:		19 October 2004
# Whom:			Pedro F. Giffuni
#
# $FreeBSD$
#

PORTNAME=	isaac
PORTVERSION=	4.2
CATEGORIES=	science
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	isaac-cfd
DISTFILES=	${PORTNAME}src.4_2${EXTRACT_SUFX} ${PORTNAME}mk.4_2${EXTRACT_SUFX}
.ifndef NOPORTDOCS
DISTFILES+=	man.4_2.ps.gz
.endif
.ifdef WITH_EXAMPLES
DISTFILES+=	example_cases${EXTRACT_SUFX}
.endif
DIST_SUBDIR=	isaac-cfd
EXTRACT_ONLY=	${PORTNAME}src.4_2${EXTRACT_SUFX} ${PORTNAME}mk.4_2${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Integrated Solution Algorithm for Arbitrary Configuration

NO_WRKSUBDIR=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
MAKEFILE=	makefile
MAKE_FLAGS=	CPPFLAGS=-I.

FFLAGS?=	-O2

.if !defined(WITH_EXAMPLES)
PLIST_SUB=	WITH_EXAMPLES="@comment "
.else
PLIST_SUB=	WITH_EXAMPLES=""
.endif

pre-configure:
	@${REINPLACE_CMD} -e 's+%%FC%%+${FC}+g ; s+%%FFLAGS%%+${FFLAGS}+;' \
	${WRKSRC}/makefile
	${FIND} ${WRKSRC} -name "*.mk" -exec	\
		${REINPLACE_CMD} -e 's|SRC= $$(HOME)/ISAAC/src|SRC= ${WRKSRC}|; \
			s|$$(FFLAGS)|${FFLAGS} -I.|' {} \;

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/isaac ${PREFIX}/bin/isaac
.ifndef NOPORTDOCS
	@${MKDIR} ${DOCSDIR}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/man.4_2.ps.gz ${DOCSDIR}
.endif
.ifdef WITH_EXAMPLES
	@${MKDIR} ${EXAMPLESDIR}
	@${TAR} -xzf ${DISTDIR}/${DIST_SUBDIR}/example_cases${EXTRACT_SUFX} \
		-C ${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
