PORTNAME=	freebsd-shar
DISTVERSIONPREFIX=	v
DISTVERSION=	15.0
PORTREVISION=	2
CATEGORIES=	sysutils

MAINTAINER=	cy@FreeBSD.org
COMMENT=	FreeBSD shar
WWW=		https://github.com/cschuber/freebsd-shar

LICENSE=	BSD3CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	cschuber
GH_PROJECT=	freebsd-shar

USES=		uidfix

MAKE_ARGS+=		BINOWN=${BINOWN} BINMODE=${BINMODE}
MAKE_ENV+=		MAKESYSPATH=/usr/src/share/mk \
			BINDIR=${PREFIX}/bin \
			MANDIR=${PREFIX}/share/man/man \
			MK_WERROR=no

WRKSRC_SUBDIR=		usr.bin/shar

.include <bsd.port.mk>
