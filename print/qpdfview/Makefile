# Created by: Gvozdikov Veniamin <g.veniamin@googlemail.com>
# $FreeBSD$

PORTNAME=	qpdfview
PORTVERSION=	0.3.7
CATEGORIES=	print
MASTER_SITES=	https://launchpadlibrarian.net/125207295/
DISTNAME=	${PORTNAME}-${PORTVERSION}beta1

MAINTAINER=	g.veniamin@googlemail.com
COMMENT=	Tabbed PDF viewer using the poppler library

LICENSE=	GPLv2

LIB_DEPENDS=	poppler-qt4:${PORTSDIR}/graphics/poppler-qt4 \
		cups:${PORTSDIR}/print/cups-client

USE_QT4=	corelib dbus gui moc_build qmake_build rcc sql svg xml

MAN1=		${PORTNAME}.1

.include <bsd.port.pre.mk>
pre-configure:
	${REINPLACE_CMD} -e 's#/usr#${PREFIX}#g;s#${PREFIX}/share/man#${PREFIX}/man#g' \
		${WRKSRC}/${PORTNAME}.pri

do-configure:
	cd ${WRKSRC} && ${QMAKE} ${QMAKEFLAGS}
.include <bsd.port.post.mk>
