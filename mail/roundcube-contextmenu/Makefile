# Created by: Alexander Moisseev <moiseev@mezonplus.ru>
# $FreeBSD$

PORTNAME=	contextmenu
PORTVERSION=	1.13
CATEGORIES=	mail
MASTER_SITES=	GH
PKGNAMEPREFIX=	roundcube-
DISTNAME=	${PORTNAME}

MAINTAINER=	moiseev@mezonplus.ru
COMMENT=	RoundCube webmail contextmenu plugin

LICENSE=	GPLv2

RUN_DEPENDS=	roundcube>=1.0:${PORTSDIR}/mail/roundcube

NO_BUILD=	yes

USE_GITHUB=	YES
GH_ACCOUNT=	JohnDoh
GH_PROJECT=	Roundcube-Plugin-Context-Menu
GH_TAGNAME=	1.13
GH_COMMIT=	53e7f7c

PLUGINDIR=	${WWWDIR:S,/${PORTNAME}$$,,}/roundcube/plugins/${PORTNAME}
RCDIR_REL=	${WWWDIR_REL:S,/${PORTNAME}$$,,}/roundcube
PLIST_SUB=	RCDIR_REL="${RCDIR_REL}"

# This target is only meant to be used by the port maintainer.
x-generate-plist: build
	make makeplist | \
	${SED} \
	    -e "s,^\(@dirrm\)try\( %%RCDIR_REL%%/plugins/contextmenu\),\1\2," \
	    >${.CURDIR}/pkg-plist.tmp

do-install:
	${MKDIR} ${STAGEDIR}${PLUGINDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${PLUGINDIR}

.include <bsd.port.mk>
