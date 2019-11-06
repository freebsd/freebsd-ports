# $FreeBSD$

PORTNAME=	free42-skins
DISTVERSION=	g20180711
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://thomasokken.com/free42/skins/
DISTNAME=	desktop-skins
DIST_SUBDIR=	${PORTNAME}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Skins for free42, simulation of the HP-42S scientific calculator

BROKEN=		unfetchable

LICENSE=	GPLv2

RUN_DEPENDS=	free42>0:misc/free42

USES=		zip
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
NO_ARCH=	yes

DATADIR=	${PREFIX}/share/free42

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/skins

.include <bsd.port.mk>
