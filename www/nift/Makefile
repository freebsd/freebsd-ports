# Created by: Mohammad S. Babaei <info@babaei.net>
# $FreeBSD$

PORTNAME=	nift
DISTVERSIONPREFIX=	v
DISTVERSION=	1.17
CATEGORIES=	www

MAINTAINER=	info@babaei.net
COMMENT=	Cross-platform open source website generator

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	nifty-site-manager
GH_PROJECT=	nsm

PLIST_FILES=	bin/nift \
		bin/nsm

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/nift
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/nsm

.include <bsd.port.mk>
