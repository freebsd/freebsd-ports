# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qoauth
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	net devel security
MASTER_SITES=	http://files.ayoy.net/qoauth/release/${PORTVERSION}/src/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 4 support for OAuth-powered network services

LIB_DEPENDS=	libqca.so:devel/qca

USES=		qmake tar:bzip2
USE_LDCONFIG=	yes
USE_QT4=	corelib qtestlib network moc_build
USE_OPENSSL=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,target.path}/pkgconfig,INSTALL_PREFIX}/libdata/pkgconfig,g' \
		${WRKSRC}/src/src.pro

.include <bsd.port.mk>
