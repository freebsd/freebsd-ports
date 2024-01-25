PORTNAME=	freebsd-bsdlabel
DISTVERSIONPREFIX=	v
DISTVERSION=	15.0
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	cy@FreeBSD.org
COMMENT=	FreeBSD bsdlabel
WWW=		https://github.com/cschuber/freebsd-bsdlabel

LICENSE=	BSD3CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	cschuber
GH_PROJECT=	freebsd-bsdlabel

USES=		uidfix

MAKE_ARGS+=		BINOWN=${BINOWN} BINMODE=${BINMODE}
MAKE_ENV+=		MAKESYSPATH=/usr/src/share/mk \
			BINDIR=${PREFIX}/sbin \
			MANDIR=${PREFIX}/share/man/man \
			MK_WERROR=no

WRKSRC_SUBDIR=		bsdlabel

.include <bsd.port.mk>
