PORTNAME=	turnd
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.1
CATEGORIES=	net

MAINTAINER=	vim@vimer.org
COMMENT=	Minimal NAT traversal and UDP relay server
WWW=		https://github.com/Yeatol/freebsd_turnd

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++23-lang
USE_GITHUB=	yes
GH_ACCOUNT=	Yeatol
GH_PROJECT=	freebsd_turnd

MAKE_ARGS=	WITH_RC_SUBR=yes

NO_TEST=	yes
PLIST_FILES=	etc/rc.d/turnd \
		sbin/turnd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/turnd ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/turnd.sh ${STAGEDIR}${PREFIX}/etc/rc.d/turnd

.include <bsd.port.mk>
