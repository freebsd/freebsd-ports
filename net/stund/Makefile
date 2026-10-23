PORTNAME=	stund
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.1
CATEGORIES=	net

MAINTAINER=	vim@vimer.org
COMMENT=	Minimal STUN (RFC 8489) binding server
WWW=		https://github.com/Yeatol/freebsd_stund

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++23-lang
USE_GITHUB=	yes
GH_ACCOUNT=	Yeatol
GH_PROJECT=	freebsd_stund

MAKE_ARGS=	WITH_RC_SUBR=yes

NO_TEST=	yes
PLIST_FILES=	etc/rc.d/stund \
		sbin/stund

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/stund ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/stund.sh ${STAGEDIR}${PREFIX}/etc/rc.d/stund

.include <bsd.port.mk>
