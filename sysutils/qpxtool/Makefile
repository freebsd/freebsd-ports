# New ports collection makefile for:	qpxtool
# Date created:		23 Mar 2006
# Whom:			Dmitry Marakasov <amdmi3@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	qpxtool
PORTVERSION=	0.5.4
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	amdmi3@mail.ru
COMMENT=	A GUI for testing CD/DVD quality and transfer rate

USE_BZIP2=	yes
USE_QT_VER=	3

MAKE_ENV+=	QTDIR="${QT_PREFIX}"
MAKE_ARGS+=	CC="${CC}" CXX="${CXX}"

PLIST_FILES=	bin/qpxtool bin/pxcontrol
PORTDOCS=	README ChangeLog

do-build:
	cd ${WRKSRC}/qpxtool && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET}
	cd ${WRKSRC}/pxcontrol && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qpxtool/qpxtool ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/pxcontrol/pxcontrol ${PREFIX}/bin

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/qpxtool/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
