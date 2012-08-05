# New ports collection makefile for:	qpdfview
# Date created:		2012-07-10
# Whom:			Gvozdikov Veniamin <g.veniamin@googlemail.com>
#
# $FreeBSD$
#

PORTNAME=	qpdfview
PORTVERSION=	0.3.1
CATEGORIES=	print
MASTER_SITES=	https://launchpadlibrarian.net/109087731/

MAINTAINER=	g.veniamin@googlemail.com
COMMENT=	Tabbed PDF viewer using the poppler library

LICENSE=	GPLv2

LIB_DEPENDS=	poppler-qt4:${PORTSDIR}/graphics/poppler-qt4 \
		cups:${PORTSDIR}/print/cups-client

USE_QT_VER=	4
QT_COMPONENTS=	corelib dbus gui moc qmake_build svg xml

MAN1=		${PORTNAME}.1

.include <bsd.port.pre.mk>
pre-configure:
	${REINPLACE_CMD} -e 's#/usr#${PREFIX}#g;s#${PREFIX}/share/man#${PREFIX}/man#g' \
		${WRKSRC}/${PORTNAME}.pri

do-configure:
	cd ${WRKSRC} && ${QMAKE} ${QMAKEFLAGS}
.include <bsd.port.post.mk>
