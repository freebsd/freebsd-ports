PORTNAME=	freebsd-telnetd
DISTVERSIONPREFIX=	v
DISTVERSION=	14.0
CATEGORIES=	net

MAINTAINER=	cy@FreeBSD.org
COMMENT=	FreeBSD telnetd

LICENSE=	BSD3CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	cschuber
GH_PROJECT=	freebsd-telnet

USES=		uidfix

MAKE_ARGS+=		BINOWN=${BINOWN} BINMODE=${BINMODE}
MAKE_ENV+=		MAKESYSPATH=/usr/src/share/mk \
			BINDIR=${PREFIX}/libexec \
			MANDIR=${PREFIX}/man/man \
			TELNETDIR=${WRKSRC}/contrib/telnet

OPTIONS_DEFINE=		IPV6
OPTIONS_DEFAULT=	IPV6

# WRKSRC_SUBDIR=		libexec/telnetd

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1300134
MAKE_ENV+=	MK_WERROR=no
.else
MAKE_ENV+=	NO_WERROR=1
.endif

post-patch:
	@${CP} ${FILESDIR}/Makefile.in ${WRKSRC}/Makefile

.include <bsd.port.mk>
