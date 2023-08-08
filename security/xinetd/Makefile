PORTNAME=	xinetd
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	2-3-15
PORTREVISION=	2
CATEGORIES=	security

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Replacement for inetd with better control and logging
WWW=		https://github.com/xinetd-org/xinetd

LICENSE=	XINETD
LICENSE_NAME=	xinetd license
LICENSE_FILE=	${WRKSRC}/COPYRIGHT
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		cpe shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME}-org
USE_RC_SUBR=	xinetd

SHEBANG_FILES=	${WRKSRC}/xinetd/xconv.pl

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-loadavg
ALL_TARGET=	build

OPTIONS_DEFINE=	IPV6 LIBWRAP XCONV
OPTIONS_DEFAULT=	LIBWRAP XCONV
OPTIONS_SUB=	yes

XCONV_DESC=	Install xconv utility (requires perl)

IPV6_CONFIGURE_WITH=	ipv6
LIBWRAP_CONFIGURE_WITH=	libwrap
XCONV_USES=	perl5
XCONV_USE=	PERL5=run

PORTSCOUT=	ignore:1

post-patch:
	@${REINPLACE_CMD} 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/xinetd/xconfig.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xinetd/xinetd ${STAGEDIR}${PREFIX}/sbin/xinetd
	${INSTALL_SCRIPT} ${WRKSRC}/xinetd/xconv.pl ${STAGEDIR}${PREFIX}/bin/xconv
	${INSTALL_MAN} ${WRKSRC}/xinetd/xinetd.conf.man ${STAGEDIR}${PREFIX}/man/man5/xinetd.conf.5
	${INSTALL_MAN} ${WRKSRC}/xinetd/xconv.pl.8 ${STAGEDIR}${PREFIX}/man/man8/xconv.8
	${INSTALL_MAN} ${WRKSRC}/xinetd/xinetd.man ${STAGEDIR}${PREFIX}/man/man8/xinetd.8
	${INSTALL_MAN} ${WRKSRC}/xinetd/xinetd.log.man ${STAGEDIR}${PREFIX}/man/man8/xinetd.log.8

.include <bsd.port.mk>
