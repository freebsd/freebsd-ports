# New ports collection Makefile for:	soprano
# Date created:				2008-01-18
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	soprano
PORTVERSION=	2.1.1
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	kde@FreeBSD.org
COMMENT=	QT4 RDF framework

LIB_DEPENDS=	clucene.0:${PORTSDIR}/textproc/clucene \
		rdf.0:${PORTSDIR}/textproc/redland

USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib dbus qtestlib qmake moc uic rcc network
USE_GNOME=	pkgconfig
USE_LDCONFIG=	yes
USE_CMAKE=	yes

post-patch:
	${MKDIR} ${WRKSRC}
	${REINPLACE_CMD} -e "s,$${LIB_SUFFIX}/pkgconfig,data/pkgconfig," \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
