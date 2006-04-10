# New ports collection makefile for:	flu
# Date created:				07 Apr 2006
# Whom:					Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	flu
PORTVERSION=	2.14
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://www.osc.edu/~jbryan/FLU/
DISTNAME=	FLU_${PORTVERSION}

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	A library containing extra widgets for FLTK

LIB_DEPENDS=	fltk:${PORTSDIR}/x11-toolkits/fltk

USE_X_PREFIX=	yes
USE_GL=		yes
INSTALLS_SHLIB=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --I=${X11BASE}/include --L=${X11BASE}/lib
USE_GMAKE=	yes
PORTDOCS=	*

SHLIB_VERSION=	0
PLIST_SUB=	SHLIB_VERSION="${SHLIB_VERSION}"
MAKE_ENV=	SHLIB_VERSION="${SHLIB_VERSION}"

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
