# $FreeBSD$

PORTNAME=	powermon
PORTVERSION=	1.0.0
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	yamagi@yamagi.org
COMMENT=	Displays the CPUs current power consumption

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	 ${WRKDIR}/${PORTNAME}-${PORTVERSION}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	yamagi
GH_TAGNAME=	${DISTVERSIONPREFIX}${PORTVERSION}

USES=		gmake

PLIST_FILES=	man/man8/powermon.8.gz sbin/powermon

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/${PORTNAME}-${PORTVERSION}/release/powermon \
		${STAGEDIR}${PREFIX}/sbin/powermon
	${INSTALL_MAN} ${WRKDIR}/${PORTNAME}-${PORTVERSION}/misc/powermon.8 \
		${STAGEDIR}${MANPREFIX}/man/man8

.include <bsd.port.mk>
