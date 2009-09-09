# New ports collection makefile for: vifm
# Date created:                      09 August 2002
# Whom:                              Stefan Walter <swalter@lettermax.de>
#
# $FreeBSD$
#

PORTNAME=	vifm
PORTVERSION=	0.5
CATEGORIES=	misc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/

MAINTAINER=	corky1951@comcast.net
COMMENT=	Ncurses based file manager with vi like keybindings

.if defined(WITH_VIFM_SCREEN)
RUN_DEPENDS=	screen:${PORTSDIR}/sysutils/screen
.endif

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes

PLIST_FILES=	bin/pauseme \
		bin/vifm \
		share/vifm/vifm-help.txt \
		share/vifm/vifm.txt \
		share/vifm/vifm.vim
PLIST_DIRS=	share/vifm

MAN1=		vifm.1
MANCOMPRESSED=	no

post-patch:
	@${REINPLACE_CMD} -e 's/resize_term/resizeterm/g' \
		${WRKSRC}/src/ui.c

.if defined(WITH_VIFM_SCREEN)
pre-build:
	@${REINPLACE_CMD} -e "s/cfg.use_screen = 0/cfg.use_screen = 1/" \
		${WRKSRC}/src/config.c
	@${REINPLACE_CMD} -e "s/USE_SCREEN=0/USE_SCREEN=1/" \
		${WRKSRC}/src/vifmrc
.else
pre-everything::
	@${ECHO_CMD} "You can define WITH_VIFM_SCREEN to add screen as a dependency."
.endif

.include <bsd.port.mk>
