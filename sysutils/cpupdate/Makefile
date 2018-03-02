# Created by: Eugene Grosbein <eugen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cpupdate
DISTVERSION=	g20180302
CATEGORIES=	sysutils

MAINTAINER=	eugen@FreeBSD.org
COMMENT=	Microcode utility for BSD

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	kernschmelze
GH_TAGNAME=	58bc0ca

PLIST_FILES=	bin/${PORTNAME} man/man8/${PORTNAME}.8.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}${MANPREFIX}/man/man8

.include <bsd.port.mk>
