# Whom:					Tom McLaughlin <tmclaugh@sdf.lonestar.org>

PKGNAMEPREFIX=	gnome-icons-

NO_BUILD=	yes
NO_ARCH=	yes

REASON=		Themes may contain artwork not done by the author. \
		Keep FreeBSD safe if theme author violated copyrights.

USES+=		gnome

do-install: icon-do-install

icon-do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/icons/
