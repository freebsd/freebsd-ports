# Created by: Matthias Petermann <matthias@petermann-it.de>
# $FreeBSD$

PORTNAME=	elementary
PORTVERSION=	0.8
DISTVERSIONPREFIX=v
CATEGORIES=	x11-themes xfce
PKGNAMEPREFIX=	xfce-icons-

MAINTAINER=	matthias@petermann-it.de
COMMENT=	Elementary icons, extended and maintained for Xfce

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	shimmerproject
GH_PROJECT=	elementary-xfce

NO_BUILD=	yes
NO_ARCH=	yes
INSTALLS_ICONS=	yes

do-install:
	cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/icons \
		"! -name README"
	${FIND} ${STAGEDIR}${PREFIX}/share/icons/ \
		-type d -empty | ${XARGS} ${RMDIR}

.include <bsd.port.mk>
