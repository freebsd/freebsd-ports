PORTNAME=	egress-monitor
DISTVERSION=	0.0.5
CATEGORIES=	sysutils

MAINTAINER=	meka@tilda.center
COMMENT=	Set network interface groups based on default routes
WWW=		https://github.com/mekanix/egress-monitor

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		uidfix
USE_RC_SUBR=	egress-monitor
SUB_FILES=	pkg-message

USE_GITHUB=	yes
GH_ACCOUNT=	mekanix

PLIST_FILES=	man/man1/egress-monitor.1.gz \
		sbin/egress-monitor

.include <bsd.port.mk>
