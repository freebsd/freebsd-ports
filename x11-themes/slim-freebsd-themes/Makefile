# $FreeBSD$

PORTNAME=	slim-freebsd-themes
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	x11-themes
MASTER_SITES=	LOCAL/decke
DISTFILES=	slim-freebsd-beastie.tar.gz slim-freebsd-simple.tar.gz

MAINTAINER=	decke@FreeBSD.org
COMMENT=	FreeBSD Theme pack for SLiM login app

LICENSE=	CC-BY-SA-4.0

RUN_DEPENDS=	slim>=0:x11/slim

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
SHAREMODE=	644
THEMEDIR=	${PREFIX}/share/slim/themes

do-install:
	${MKDIR} ${STAGEDIR}${THEMEDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${THEMEDIR}/)

.include <bsd.port.mk>
