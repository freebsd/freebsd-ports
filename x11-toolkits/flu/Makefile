# New ports collection makefile for:	flu
# Date created:				07 Apr 2006
# Whom:					Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	flu
PORTVERSION=	2.14
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://www.osc.edu/~jbryan/FLU/
DISTNAME=	FLU_${PORTVERSION}

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	A library containing extra widgets for FLTK

LIB_DEPENDS=	fltk:${PORTSDIR}/x11-toolkits/fltk

USE_X_PREFIX=	yes
USE_GL=		yes
INSTALLS_SHLIB=	yes
NO_FILTER_SHLIBS=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --I=${X11BASE}/include --L=${X11BASE}/lib
USE_GMAKE=	yes
PORTDOCS=	*

post-patch:
	@${RM} -rf ${WRKSRC}/doc/CVS

post-install:
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.cpp ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
