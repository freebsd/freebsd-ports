# Created by: Nicole Reid <root@cooltrainer.org>
# $FreeBSD$

PORTNAME=	elementary
PORTVERSION=	4.3.1
CATEGORIES=	x11-themes gnome
PKGNAMEPREFIX=	gnome-icons-

MAINTAINER=	root@cooltrainer.org
COMMENT=	Elementary icon set

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gnome
USE_GITHUB=	yes
GH_PROJECT=	icons

NO_BUILD=	yes
NO_ARCH=	yes
INSTALLS_ICONS=	yes

do-install:
	cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/icons/elementary \
		"! -name *\.VolumeIcon* ! -name pre-commit ! -name CMakeLists.txt"
	${FIND} ${STAGEDIR}${PREFIX}/share/icons/elementary/ \
		-type d -empty | ${XARGS} ${RMDIR}

.include <bsd.port.mk>
