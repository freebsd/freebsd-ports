PORTNAME=	freebsd-fdisk
DISTVERSIONPREFIX=	v
DISTVERSION=	15.0
CATEGORIES=	sysutils

MAINTAINER=	cy@FreeBSD.org
COMMENT=	FreeBSD fdisk
WWW=		https://github.com/cschuber/freebsd-fdisk

LICENSE=	BSD3CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	cschuber
GH_PROJECT=	freebsd-fdisk

USES=		uidfix

MAKE_ARGS+=		BINOWN=${BINOWN} BINMODE=${BINMODE}
MAKE_ENV+=		MAKESYSPATH=/usr/src/share/mk \
			BINDIR=${PREFIX}/sbin \
			MANDIR=${PREFIX}/share/man/man \
			MK_WERROR=no

WRKSRC_SUBDIR=		fdisk

.include <bsd.port.mk>
