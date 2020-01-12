# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	eschalot
PORTVERSION=	1.2.0.20191006
CATEGORIES=	security

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Vanity onion address generator for Tor

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	ReclaimYourPrivacy
GH_TAGNAME=	a45bad5

USES=		gmake ssl
MAKE_ENV=	INSTALL="${INSTALL_PROGRAM}"
MAKE_ARGS=	PREFIX="${STAGEDIR}${PREFIX}"
TEST_TARGET=	test

PLIST_FILES=	bin/eschalot bin/worgen

post-patch:
	@${REINPLACE_CMD} -e '/CFLAGS.*-O2/d' ${WRKSRC}/Makefile

.include <bsd.port.mk>
