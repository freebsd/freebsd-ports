# Created by: Stefan Walter <swalter@lettermax.de>
# $FreeBSD$

PORTNAME=	vifm
PORTVERSION=	0.6.3
CATEGORIES=	misc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}

MAINTAINER=	kaspars@bankovskis.lv
COMMENT=	Ncurses based file manager with vi like keybindings

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	VIFM_SCREEN
VIFM_SCREEN_DESC=	Use vifm with the screen program

USES=		ncurses
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-gtk
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOHEADER="${TRUE}" \
		AUTOMAKE="${TRUE}"

MAN1=		vifm.1
PLIST_FILES=	bin/vifm \
		bin/vifm-pause \
		%%DATADIR%%/startup \
		%%DATADIR%%/vifm-help.txt \
		%%DATADIR%%/vifm.txt \
		%%DATADIR%%/vifm.vim \
		%%DATADIR%%/vifmrc
PLIST_DIRS=	%%DATADIR%%

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MVIFM_SCREEN}
RUN_DEPENDS=	screen:${PORTSDIR}/sysutils/screen
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/resize_term/resizeterm/g' \
		${WRKSRC}/src/ui.c
.if ${PORT_OPTIONS:MVIFM_SCREEN}
	@${REINPLACE_CMD} -e "s/cfg.use_screen = 0/cfg.use_screen = 1/" \
		${WRKSRC}/src/config.c
	@${REINPLACE_CMD} -e "s/USE_SCREEN=0/USE_SCREEN=1/" \
		${WRKSRC}/src/vifmrc
.endif

.include <bsd.port.mk>
