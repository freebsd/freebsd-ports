# New ports collection makefile for:	GLPK
# Date created:		16 December 2000
# Whom:			Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	glpk
PORTVERSION=	4.25
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	glpk

MAINTAINER=	demon@FreeBSD.org
COMMENT=	A GNU Linear Programming Kit

LIB_DEPENDS=	gmp:${PORTSDIR}/math/libgmp4

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
CFLAGS+=	-trigraphs
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

.if !defined(NOPORTDOCS)
PORTDOCS=	bench.txt bench1.txt glpk.ps glpk_faq.txt gmpl.ps \
		gomory.djvu opb.txt
.endif

post-install:
	@${INSTALL_DATA} ${WRKSRC}/include/*.h ${PREFIX}/include/

.if !defined(NOPORTDOCS)
	@${CP} ${WRKSRC}/doc/memo/gomory.djvu ${WRKSRC}/doc/
	@${MKDIR} ${DOCSDIR}
	for docfile in ${PORTDOCS} ; do \
		${INSTALL_MAN} ${WRKSRC}/doc/$${docfile} ${DOCSDIR} ; \
	done
.endif

.include <bsd.port.mk>
