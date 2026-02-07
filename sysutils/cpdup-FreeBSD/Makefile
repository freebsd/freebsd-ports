PORTNAME=	cpdup
DISTVERSION=	1.0.0
CATEGORIES=	sysutils
PKGNAMESUFFIX=	-FreeBSD

MAINTAINER=	gmarco@giovannelli.it
COMMENT=	Comprehensive filesystem mirroring and backup program
WWW=		https://github.com/freebsd/cpdup

LICENSE=	BSD3CLAUSE

USES=		ssl tar:xz uidfix
USE_GITHUB=	yes
GH_ACCOUNT=	freebsd
MAKEFILE=	Makefile.bsd

CONFLICTS_INSTALL=	cpdup

PLIST_FILES=	bin/cpdup \
		share/man/man1/cpdup.1.gz

.include <bsd.port.mk>
