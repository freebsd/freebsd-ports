# New ports collection makefile for:	GLPK
# Date created:		16 December 2000
# Whom:			Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	glpk
PORTVERSION=	4.24
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	glpk

MAINTAINER=	demon@FreeBSD.org
COMMENT=	A GNU Linear Programming Kit

LIB_DEPENDS=	gmp:${PORTSDIR}/math/libgmp4

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_GMAKE=	yes
USE_LDCONFIG=	yes
CFLAGS+=	-trigraphs

GMPL_H= 	glpavl.h glpdmp.h glplib.h glpmpl.h glprng.h glpstd.h
GMPLDIR=	${LOCALBASE}/include/gmpl

.if !defined(NOPORTDOCS)
PORTDOCS=	bench.txt bench1.txt glpk.ps glpk_faq.txt gmpl.ps opb.txt
.endif

post-install:
	@${MKDIR} ${GMPLDIR}
	for incfile in ${GMPL_H} ; do \
		${INSTALL_DATA} ${WRKSRC}/include/$${incfile} ${GMPLDIR} ; \
	done

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	for docfile in ${PORTDOCS} ; do \
		${INSTALL_MAN} ${WRKSRC}/doc/$${docfile} ${DOCSDIR} ; \
	done
.endif

.include <bsd.port.mk>
