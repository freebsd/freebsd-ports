PORTNAME=	libsunacl
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/freenas/libsunacl/releases/download/v${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Wrapper providing SunOS NFSv4 ACL API

LICENSE=	BSD2CLAUSE

USES=		uidfix
USE_LDCONFIG=	yes
PLIST_FILES=	include/sunacl.h lib/libsunacl.a lib/libsunacl.so.1 lib/libsunacl.so
MAKE_ENV=	WITHOUT_PROFILE=yes

.include <bsd.port.mk>
