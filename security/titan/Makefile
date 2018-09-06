# $FreeBSD$

PORTNAME=	titan
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3
CATEGORIES=	security

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Command line password manager and file encryption program

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake localbase:ldflags sqlite ssl
USE_GITHUB=	yes
GH_ACCOUNT=	nrosvall

MAKE_ENV=	MANDIR=${PREFIX}/man

PLIST_FILES=	bin/titan man/man1/titan.1.gz

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/titan

.include <bsd.port.mk>
