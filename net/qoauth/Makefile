# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qoauth
PORTVERSION=	2.0.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	net devel security

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 4 support for OAuth-powered network services

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

LIB_DEPENDS=	libqca.so:devel/qca@qt4

USES=		qmake:outsource qt:4
USE_LDCONFIG=	yes
USE_QT=		corelib qtestlib network moc_build

USE_GITHUB=	yes
GH_ACCOUNT=	ayoy

post-patch:
	@${REINPLACE_CMD} -e 's,target.path}/pkgconfig,INSTALL_PREFIX}/libdata/pkgconfig,g' \
		${WRKSRC}/src/src.pro

.include <bsd.port.mk>
