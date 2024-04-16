PORTNAME=	freebsd-routed
DISTVERSIONPREFIX=	v
DISTVERSION=	15.0.1
CATEGORIES=	net

MAINTAINER=	cy@FreeBSD.org
COMMENT=	FreeBSD routed
WWW=		https://github.com/cschuber/freebsd-routed

LICENSE=	BSD3CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	cschuber
GH_PROJECT=	freebsd-routed

USES=		uidfix

MAKE_ARGS+=		BINOWN=${BINOWN} BINMODE=${BINMODE}
MAKE_ENV+=		MAKESYSPATH=/usr/src/share/mk \
			BINDIR=${PREFIX}/sbin \
			MANDIR=${PREFIX}/share/man/man \
			MK_WERROR=no

# WRKSRC_SUBDIR=		sbin/routed

post-patch:
	@${CP} ${FILESDIR}/Makefile.in ${WRKSRC}/Makefile

post-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/libexec/rc/rc.d/routed ${STAGEDIR}${PREFIX}/etc/rc.d

.include <bsd.port.mk>
