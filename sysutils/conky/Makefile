# New ports collection makefile for:	conky
# Date created:				2005-08-27
# Whom:					Roman Bogorodskiy <novel@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	conky
PORTVERSION=	1.3.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	novel@FreeBSD.org
COMMENT=	An advanced, highly configurable system monitor for X

USE_BZIP2=	yes
HAS_CONFIGURE=	yes
USE_X_PREFIX=	yes

MAN1=		conky.1

PORTDOCS=	README AUTHORS ChangeLog TODO \
		docs.html variables.html config_settings.html

.if defined(WITH_XFT)
LIB_DEPENDS+=		Xft.2:${PORTSDIR}/x11-fonts/libXft
CONFIGURE_ARGS+=	--enable-xft
.else
CONFIGURE_ARGS+=	--disable-xft
.endif

.if !defined(WITHOUT_OWN_WINDOW)
CONFIGURE_ARGS+=	--enable-own-window
.else
CONFIGURE_ARGS+=	--disable-own-widnow
.endif

.if defined(WITH_MPD)
CONFIGURE_ARGS+=	--enable-mpd
.else
CONFIGURE_ARGS+=	--disable-mpd
.endif

.if defined(WITHOUT_DOUBLE_BUFFER)
CONFIGURE_ARGS+=	--disable-double-buffer
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/conky ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/conky.1 ${PREFIX}/man/man1

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/conkyrc.sample ${EXAMPLESDIR}

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in README AUTHORS ChangeLog TODO
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.for i in docs.html variables.html config_settings.html
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"Doesn't compile on 4.x"
.endif

.include <bsd.port.post.mk>
