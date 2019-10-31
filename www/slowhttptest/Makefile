# $FreeBSD$

PORTNAME=	slowhttptest
DISTVERSIONPREFIX=	v
DISTVERSION=	1.8
CATEGORIES=	www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Application Layer DoS attack simulator for pentesting

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf ssl
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	shekyan

PLIST_FILES=	bin/slowhttptest \
		man/man1/slowhttptest.1.gz

.include <bsd.port.mk>
