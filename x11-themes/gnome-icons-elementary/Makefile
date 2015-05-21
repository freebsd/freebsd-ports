# Created by: Nicole Reid <root@cooltrainer.org>
# $FreeBSD$

PORTNAME=	elementary
PORTVERSION=	3.1
CATEGORIES=	x11-themes gnome
MASTER_SITES=	https://launchpadlibrarian.net/147829592/ \
	https://launchpad.net/elementaryicons/3.x/${PORTVERSION}/+download/
PKGNAMEPREFIX=	gnome-icons-
DISTNAME=	${PORTNAME}icons${PORTVERSION}

MAINTAINER=	root@cooltrainer.org
COMMENT=	Elementary icon set

LICENSE=	GPLv3

NO_BUILD=	yes
INSTALLS_ICONS=	yes

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/icons/elementary/ \
		"! -name 'plist' ! -name '*.bak' ! -name '${LICENSE}' ! -path 'stage/*' "
	${FIND} ${STAGEDIR}${PREFIX}/share/icons/elementary/ -depth 2 \
		-type d -empty | \
		${XARGS} ${RMDIR}

.include <bsd.port.mk>
