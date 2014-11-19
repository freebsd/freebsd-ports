# Created by: wmoran
# $FreeBSD$

PORTNAME=	jailme
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	freebsd-ports-maintainers@intermedix.com
COMMENT=	Setuid version of jexec to allow normal users access to jails

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	Intermedix
GH_COMMIT=	a54cc09

PLIST_FILES=	"@(,,4751) sbin/jailme"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jailme ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
