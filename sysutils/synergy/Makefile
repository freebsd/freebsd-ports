# New ports collection makefile for:	synergy
# Date created:		26 March 2003
# Whom:			Kevin Lo <kevlo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	synergy
PORTVERSION=	1.3.6
DISTVERSIONSUFFIX=	-Source
CATEGORIES=	sysutils
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Mouse and keyboard sharing utility

USE_CMAKE=	yes
USE_XORG=	ice xtst x11 sm
MAKE_ENV+=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" \

CFLAGS+=	-L${LOCALBASE}/lib -I${LOCALBASE}/include

post-patch:
	@${ECHO_CMD} >> ${WRKSRC}/lib/base/LogOutputters.cpp

do-install:
.for f in synergys synergyc
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/${PORTNAME}.conf ${EXAMPLESDIR}

.include <bsd.port.mk>
