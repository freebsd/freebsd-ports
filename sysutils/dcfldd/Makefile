PORTNAME=	dcfldd
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.1
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Enhanced dd tool with MD5 hashing capability
WWW=		https://github.com/resurrecting-open-source-projects/dcfldd

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
USE_GITHUB=	yes
GH_ACCOUNT=	resurrecting-open-source-projects

PLIST_FILES=	bin/dcfldd \
		share/man/man1/dcfldd.1.gz

.include <bsd.port.mk>
