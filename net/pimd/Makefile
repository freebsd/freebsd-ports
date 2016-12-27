# $FreeBSD$

PORTNAME=	pimd
PORTVERSION=	2.3.2
CATEGORIES=	net

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	Lightweight stand-alone PIM-SM v2 multicast routing daemon

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	troglobit
GH_PROJECT=	libite:libite
GH_TAGNAME=	v1.4.4:libite
GH_SUBDIR=	libite:libite

USE_RC_SUBR=	${PORTNAME}

HAS_CONFIGURE=	yes
MAKE_ARGS=	prefix="${PREFIX}" sysconfdir="${PREFIX}/etc/"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pimd ${STAGEDIR}${PREFIX}/sbin/
	${INSTALL_DATA} ${WRKSRC}/pimd.conf \
		${STAGEDIR}${PREFIX}/etc/pimd.conf.sample
	${INSTALL_SCRIPT} ${FILESDIR}/pimd.in \
		${STAGEDIR}${PREFIX}/etc/rc.d/pimd
	${INSTALL_MAN} ${WRKSRC}/pimd.8 ${STAGEDIR}${MANPREFIX}/man/man8/

.include <bsd.port.mk>
