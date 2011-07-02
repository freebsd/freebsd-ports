# New ports collection makefile for: vifm
# Date created:                      09 August 2002
# Whom:                              Stefan Walter <swalter@lettermax.de>
#
# $FreeBSD$
#

PORTNAME=	vifm
PORTVERSION=	0.6.2
CATEGORIES=	misc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ncurses based file manager with vi like keybindings

OPTIONS=	VIFM_SCREEN "Use vifm with the screen program" off

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_BZIP2=	yes
USE_NCURSES=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-gtk
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOHEADER="${TRUE}" \
		AUTOMAKE="${TRUE}"

MAN1=		vifm.1
PLIST_FILES=	bin/pauseme \
		bin/vifm \
		%%DATADIR%%/startup \
		%%DATADIR%%/vifm-help.txt \
		%%DATADIR%%/vifm.txt \
		%%DATADIR%%/vifm.vim \
		%%DATADIR%%/vifmrc
PLIST_DIRS=	%%DATADIR%%

.include <bsd.port.pre.mk>

.if defined(WITH_VIFM_SCREEN)
RUN_DEPENDS=	screen:${PORTSDIR}/sysutils/screen
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/resize_term/resizeterm/g' \
		${WRKSRC}/src/ui.c
.if defined(WITH_VIFM_SCREEN)
	@${REINPLACE_CMD} -e "s/cfg.use_screen = 0/cfg.use_screen = 1/" \
		${WRKSRC}/src/config.c
	@${REINPLACE_CMD} -e "s/USE_SCREEN=0/USE_SCREEN=1/" \
		${WRKSRC}/src/vifmrc
.endif

.include <bsd.port.post.mk>
