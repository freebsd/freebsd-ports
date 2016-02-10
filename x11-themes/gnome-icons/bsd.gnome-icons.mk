# Whom:					Tom McLaughlin <tmclaugh@sdf.lonestar.org>
# $FreeBSD$

PKGNAMEPREFIX=	gnome-icons-

NO_BUILD=	yes
NO_ARCH=	yes

REASON=		Themes may contain artwork not done by the author. \
		Keep FreeBSD safe if theme author violated copyrights.

WANT_GNOME=	yes
INSTALLS_ICONS=	yes

do-install: icon-do-install

icon-do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/icons/
