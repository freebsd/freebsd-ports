# New ports collection makefile for:	Mapagi
# Date created:				Mon Oct 27 02:39:47 UTC 2003
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mapagi
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://members.ferrara.linux.it/calicant/mapagi/

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Pagination utility that prints your images/comics in 'in folio' format

USE_QT_VER=	3
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_SIZE=	yes

QMAKE?=	${X11BASE}/bin/qmake
QTDIR?=	${QT_PREFIX}

CONFIGURE_ENV+=	QTDIR=${QTDIR}
MAKE_ENV+=	QTDIR=${QTDIR}

DOC_FILES=	COPYING ChangeLog INSTALL README TODO

do-configure:
	@cd ${CONFIGURE_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${QMAKE}

post-configure:
# fix C{C,XX} locations
	@${REINPLACE_CMD} -E \
		-e 's|^(CC[[:space:]]*=).*$$|\1${CC}|' \
		-e 's|^(CXX[[:space:]]*=).*$$|\1${CXX}|' \
		-e 's|^(LINK[[:space:]]*=).*$$|\1${CXX}|' \
		${BUILD_WRKSRC}/${MAKEFILE}

do-install:
	@${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/${PORTNAME} ${PREFIX}/bin
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${INSTALL_WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif # NOPORTDOCS

.include <bsd.port.mk>
