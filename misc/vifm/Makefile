# New ports collection makefile for: vifm
# Date created:                      09 August 2002
# Whom:                              Stefan Walter <swalter@lettermax.de>
#
# $FreeBSD$
#

PORTNAME=	vifm
PORTVERSION=	0.3a
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	stefan@FreeBSD.org
COMMENT=	Ncurses based file manager with vi like keybindings

.if defined(WITH_VIFM_SCREEN)
RUN_DEPENDS=	screen:${PORTSDIR}/sysutils/screen
.endif

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes

PLIST_FILES=	bin/pauseme \
		bin/screen-open-region-with-program \
		bin/screen-run-program-in-region \
		bin/vifm \
		share/vifm/vifm-0.2.help.txt \
		share/vifm/vifm.txt \
		share/vifm/vifm.vim
PLIST_DIRS=	share/vifm

post-patch:
	@${REINPLACE_CMD} -e 's/resize_term/resizeterm/g' \
		${WRKSRC}/src/ui.c

.if defined(WITH_VIFM_SCREEN)
pre-build:
	@${REINPLACE_CMD} -e "s/cfg.use_screen = 0/cfg.use_screen = 1/" \
		${WRKSRC}/src/config.c
	@${REINPLACE_CMD} -e "s/USE_SCREEN=0/USE_SCREEN=1/" \
		${WRKSRC}/src/vifmrc0.2
.else
pre-everything::
	@${ECHO_CMD} "You can define WITH_VIFM_SCREEN to add screen as a dependency."
.endif

.include <bsd.port.mk>
