PORTNAME=	identity_smtp
DISTVERSION=	1.6.0
PORTEPOCH=	1
CATEGORIES=	mail
PKGNAMEPREFIX=	roundcube-
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	meta@FreeBSD.org
COMMENT=	Roundcube plugin to setup different SMTP settings per identity
WWW=		https://github.com/deflomu/Roundcube-SMTP-per-Identity-Plugin

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	php:flavors
NO_BUILD=	yes
NO_ARCH=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	deflomu
GH_PROJECT=	Roundcube-SMTP-per-Identity-Plugin

PLUGINDIR=	${WWWDIR:S,/${PORTNAME}$$,,}/roundcube/plugins/${PORTNAME}
RCDIR_REL=	${WWWDIR_REL:S,/${PORTNAME}$$,,}/roundcube
PLIST_SUB=	RCDIR_REL="${RCDIR_REL}"

do-install:
	${MKDIR} ${STAGEDIR}${PLUGINDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${PLUGINDIR}

.include <bsd.port.mk>
