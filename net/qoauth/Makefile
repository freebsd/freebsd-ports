# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qoauth
PORTVERSION=	1.0.1
CATEGORIES=	net devel security
MASTER_SITES=	http://files.ayoy.net/qoauth/release/${PORTVERSION}/src/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 4 support for OAuth-powered network services

BUILD_DEPENDS=	qca-ossl>=2.0.0.b3:${PORTSDIR}/security/qca-ossl
LIB_DEPENDS=	qca.2:${PORTSDIR}/devel/qca
RUN_DEPENDS=	qca-ossl>=2.0.0.b3:${PORTSDIR}/security/qca-ossl

USES=		qmake
USE_LDCONFIG=	yes
USE_BZIP2=	yes
USE_QT4=	corelib qtestlib network moc_build
USE_OPENSSL=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,target.path}/pkgconfig,INSTALL_PREFIX}/libdata/pkgconfig,g' \
		${WRKSRC}/src/src.pro

.include <bsd.port.mk>
