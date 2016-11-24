# Created by: Nicole Reid <root@cooltrainer.org>
# $FreeBSD$

PORTNAME=	elementary
PORTVERSION=	4.0.1.1
CATEGORIES=	x11-themes gnome
MASTER_SITES=	https://launchpadlibrarian.net/294159209/ \
	https://launchpad.net/elementaryicons/4.x/${PORTVERSION}/+download/
PKGNAMEPREFIX=	gnome-icons-
DISTNAME=	${PORTNAME}-icon-theme-${PORTVERSION}

MAINTAINER=	root@cooltrainer.org
COMMENT=	Elementary icon set

LICENSE=	GPLv3

USES=	tar:xz
NO_BUILD=	yes
NO_ARCH=	yes
INSTALLS_ICONS=	yes

do-install:
	cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/icons/elementary \
		"! -name *\.VolumeIcon* ! -name pre-commit"
	${FIND} ${STAGEDIR}${PREFIX}/share/icons/elementary/ \
		-type d -empty | ${XARGS} ${RMDIR}

.include <bsd.port.mk>
