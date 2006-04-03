# New ports collection makefile for:	qpxtool
# Date created:		23 Mar 2006
# Whom:			Dmitry Marakasov <amdmi3@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	qpxtool
PORTVERSION=	0.5.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	amdmi3@mail.ru
COMMENT=	A GUI for testing CD/DVD quality and transfer rate

USE_BZIP2=	yes
USE_QT_VER=	3

MAKE_ENV+=	QTDIR="${QT_PREFIX}"
MAKE_ARGS+=	CC="${CC}" CXX="${CXX}"

PLIST_FILES=	bin/qpxtool
PORTDOCS=	README ChangeLog

post-patch:
	@${REINPLACE_CMD} 's|};||' ${WRKSRC}/transport.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qpxtool ${PREFIX}/bin

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
