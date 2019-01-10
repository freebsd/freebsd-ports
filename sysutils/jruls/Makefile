# $FreeBSD$

PORTNAME=	jruls
PORTVERSION=	0.2
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	606u@dir.bg
COMMENT=	Display and update FreeBSD jails resource usage

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes

GH_ACCOUNT=	606u

PLIST_FILES=	bin/jruls

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jruls ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
