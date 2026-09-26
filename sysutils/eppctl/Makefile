PORTNAME=	eppctl
DISTVERSION=	0.0.20260926
CATEGORIES=	sysutils

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Intel HWP Energy/Performance utility
WWW=		https://github.com/osokin/eppctl/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

CPE_VENDOR=	google

USE_GITHUB=	yes
GH_ACCOUNT=	osokin
GH_TAGNAME=	7d074df

PLIST=		bin/eppctl
MANS=		eppctl.8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/eppctl ${STAGEDIR}${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/eppctl.8.gz ${STAGEDIR}${PREFIX}/share/man/man8/

.include <bsd.port.mk>
