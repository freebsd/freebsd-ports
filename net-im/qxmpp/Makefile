# New ports collection makefile for:	qxmpp
# Date created:		2012-01-07
# Whom:			Gvozdikov Veniamin <g.veniamin@googlemail.com>
#
# $FreeBSD$
#

PORTNAME=	qxmpp
PORTVERSION=	0.3.91
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	vg@FreeBSD.org
COMMENT=	QXmpp is an xmpp client library based on Qt & C++

LICENSE=	LGPL21

USE_QT4=	gui network xml qmake_build uic_build moc_build rcc_build

CONFLICTS=	${PORTNAME}-leechcraft-[0-9]*

do-configure:
	${REINPLACE_CMD} -e 's|%%QT_LIBDIR_REL%%|${QT_LIBDIR_REL}|g' \
		${WRKSRC}/src/src.pro
	${REINPLACE_CMD} -e 's|%%DOCSDIR%%|${DOCSDIR}|g' \
		${WRKSRC}/${PORTNAME}.pro
	cd ${WRKSRC} && ${QMAKE} ${QMAKEFLAGS} PREFIX=${PREFIX}

.include <bsd.port.mk>
