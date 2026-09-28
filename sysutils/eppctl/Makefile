PORTNAME=	eppctl
DISTVERSION=	0.0.20260928
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	osa@FreeBSD.org
COMMENT=	HWP Energy/Performance utility
WWW=		https://github.com/osokin/eppctl/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

CPE_VENDOR=	osokin
CPE_PRODUCT=	${PORTNAME}

USE_GITHUB=	yes
GH_ACCOUNT=	osokin
GH_TAGNAME=	1250458

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	does not support

PLIST_FILES=	sbin/eppctl \
		share/man/man8/eppctl.8.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/eppctl ${STAGEDIR}${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/eppctl.8.gz ${STAGEDIR}${PREFIX}/share/man/man8/

.include <bsd.port.mk>
