PORTNAME=		pnscan
DISTVERSIONPREFIX=	v
DISTVERSION=		1.14.1
PORTREVISION=	1
CATEGORIES=		sysutils security

MAINTAINER=		pen@lysator.liu.se
COMMENT=		Parallel Network Scanner
WWW=		https://github.com/ptrrkssn/pnscan

LICENSE=		BSD3CLAUSE
LICENSE_FILE=		${WRKSRC}/LICENSE

USE_GITHUB=		yes
GH_ACCOUNT=		ptrrkssn

GNU_CONFIGURE=		yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
INSTALL_TARGET=		install-strip

PLIST_FILES=		bin/pnscan \
			share/man/man1/pnscan.1.gz

.include <bsd.port.mk>
