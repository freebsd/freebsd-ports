# New ports collection makefile for: vifm
# Date created:                      09 August 2002
# Whom:                              Stefan Walter <swalter@lettermax.de>
#
# $FreeBSD$
#

PORTNAME=	vifm
PORTVERSION=	0.1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	vifm

MAINTAINER=	swalter@lettermax.de

.if defined(WITH_VIFM_SCREEN)
RUN_DEPENDS=	screen:${PORTSDIR}/misc/screen
.else
pre-everything:
	@${ECHO_CMD} "You can define WITH_VIFM_SCREEN to add screen as a dependency."
.endif

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes

.if defined(WITH_VIFM_SCREEN)
pre-build:
	@${REINPLACE_CMD} -e "s/cfg.use_screen = 0/cfg.use_screen = 1/" \
		${BUILD_WRKSRC}/src/config.c
	@${REINPLACE_CMD} -e "s/USE_SCREEN=0/USE_SCREEN=1/" \
		${BUILD_WRKSRC}/src/vifmrc0.1
.endif

.include <bsd.port.mk>
