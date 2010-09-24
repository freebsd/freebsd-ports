# New ports collection makefile for:	qoauth
# Date created:		2010-09-18
# Whom:			Steve Wills <swills@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	qoauth
PORTVERSION=	1.0.1
CATEGORIES=	net devel security
MASTER_SITES=	http://files.ayoy.net/qoauth/release/${PORTVERSION}/src/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	kde@FreeBSD.org
COMMENT=	QT support for OAuth-powered network services

BUILD_DEPENDS+=	qca-ossl>=2.0.0.b3:${PORTSDIR}/security/qca-ossl
LIB_DEPENDS=	qca.2:${PORTSDIR}/devel/qca
RUN_DEPENDS=	qca-ossl>=2.0.0.b3:${PORTSDIR}/security/qca-ossl

USE_LDCONFIG=	yes
USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib qtestlib network qmake_build moc_build
HAS_CONFIGURE=	yes
USE_OPENSSL=	yes

QMAKEFLAGS+=	PREFIX=${PREFIX}

post-patch:
	@${REINPLACE_CMD} -e 's,target.path}/pkgconfig,INSTALL_PREFIX}/libdata/pkgconfig,g' \
		${WRKSRC}/src/src.pro

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${MAKE_ENV} \
		${QMAKE} ${QMAKEFLAGS} qoauth.pro

.include <bsd.port.mk>
