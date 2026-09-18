PORTNAME=	pimd
DISTVERSION=	3.1.0
CATEGORIES=	net

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	Lightweight stand-alone PIM-SM/SSM multicast routing daemon
WWW=		https://github.com/ocochard/pimd

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf:build

USE_GITHUB=	yes
GH_ACCOUNT=	ocochard

USE_RC_SUBR=	${PORTNAME}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc \
		--localstatedir=/var

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/pimd ${STAGEDIR}${PREFIX}/sbin/
	${INSTALL_PROGRAM} ${WRKSRC}/src/pimctl ${STAGEDIR}${PREFIX}/sbin/
	${INSTALL_DATA} ${WRKSRC}/pimd.conf \
		${STAGEDIR}${PREFIX}/etc/pimd.conf.sample
	${INSTALL_MAN} ${WRKSRC}/man/pimd.8 ${STAGEDIR}${PREFIX}/share/man/man8/
	${INSTALL_MAN} ${WRKSRC}/man/pimctl.8 ${STAGEDIR}${PREFIX}/share/man/man8/
	${INSTALL_MAN} ${WRKSRC}/man/pimd.conf.5 ${STAGEDIR}${PREFIX}/share/man/man5/

.include <bsd.port.mk>
