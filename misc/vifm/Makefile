# New ports collection makefile for: vifm
# Date created:                      09 August 2002
# Whom:                              Stefan Walter <swalter@lettermax.de>
#
# $FreeBSD$
#

PORTNAME=	vifm
PORTVERSION=	0.2a
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	vifm

MAINTAINER=	sw@gegenunendlich.de
COMMENT=	Ncurses based file manager with vi like keybindings

WRKSRC=		${WRKDIR}/${PORTNAME}

.if defined(WITH_VIFM_SCREEN)
RUN_DEPENDS=	screen:${PORTSDIR}/misc/screen
.else
pre-everything::
	@${ECHO_CMD} "You can define WITH_VIFM_SCREEN to add screen as a dependency."
.endif

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes

PLIST_FILES=	bin/pauseme \
		bin/vifm \
		share/vifm/vifm-0.2.help.txt \
		share/vifm/vifm.txt \
		share/vifm/vifm.vim \
		share/vifm/vifmrc0.2
PLIST_DIRS=	share/vifm

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure

.if defined(WITH_VIFM_SCREEN)
pre-build:
	@${REINPLACE_CMD} -e "s/cfg.use_screen = 0/cfg.use_screen = 1/" \
		${WRKSRC}/src/config.c
	@${REINPLACE_CMD} -e "s/USE_SCREEN=0/USE_SCREEN=1/" \
		${WRKSRC}/src/vifmrc0.2
.endif

.include <bsd.port.mk>
