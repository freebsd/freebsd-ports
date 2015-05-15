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

pre-install:
	cd ${WRKSRC} && ${FIND} * -type d ! -empty \
		! -path 'stage*' \
		-exec ${MKDIR} -m 0755 \
		${STAGEDIR}${PREFIX}/share/icons/elementary/"{}" \;

do-install:
	cd ${WRKSRC} && ${FIND} * ! -type d ! -name 'plist' ! -name '*.bak' \
		! -name '${LICENSE}' \
		! -path 'stage/*' \
		-exec ${INSTALL_DATA} ${WRKSRC}/"{}" \
		${STAGEDIR}${PREFIX}/share/icons/elementary/"{}" \;

.include <bsd.port.mk>
