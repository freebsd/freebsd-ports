# New ports collection makefile for:	flux-art
# Date created:         5 August 2004
# Whom:               	Ilya Khamushkin <ilya@space.rootshell.ru>
#
# $FreeBSD$
#

PORTNAME=	flux-art
PORTVERSION=	0.1
CATEGORIES=	x11-themes
MASTER_SITES=	http://www.iluxa.kremenchug.net/files/

MAINTAINER=	ilya@space.rootshell.ru
COMMENT=	Flux-art themes pack for fluxbox-devel

RUN_DEPENDS=	fluxbox:${PORTSDIR}/x11-wm/fluxbox-devel

CONFLICTS=	fluxbox-fluxmod-*

USE_BZIP2=	yes
USE_X_PREFIX=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
INSTALL_DIR=	${PREFIX}/share/fluxbox/styles
THEME_CMD=	cd ${WRKSRC}; ${FIND} * -name theme.cfg
DIRS_CMD=	cd ${WRKSRC}; ${FIND} * -type d
DATA_CMD=	cd ${WRKSRC}; ${FIND} * -type f

pre-install:
	@for theme in `${THEME_CMD}`; do \
		${SED} -i '' -e "s,~/.fluxbox,${X11BASE}/share/fluxbox," ${WRKSRC}/$$theme; \
	done

do-install:
	@for dir in `${DIRS_CMD}`; do \
		${MKDIR} ${INSTALL_DIR}/$$dir; \
	done

	@for data in `${DATA_CMD}`; do	\
		${INSTALL_DATA} ${WRKSRC}/$$data ${INSTALL_DIR}/$$data; \
	done

.include <bsd.port.mk>
