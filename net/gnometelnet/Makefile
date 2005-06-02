# New ports collection makefile for:	gnometelnet
# Date created:				2 August 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnometelnet
PORTVERSION=	2.5
PORTREVISION=	1
CATEGORIES=	net gnome
MASTER_SITES=	http://www.cyest.org/downloads/
DISTNAME=	${PORTNAME:S/gnome/gnome-/}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A nice frontend to the telnet, ssh, and rlogin clients for GNOME

WANT_AUTOMAKE_VER=15
USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomelibs gnomeprefix
USE_GMAKE=	yes
USE_LIBTOOL_VER=15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

pre-configure:
	@${LN} -sf ${AUTOMAKE_DIR}/install-sh ${WRKSRC}
	@${RM} -f ${WRKSRC}/config.cache
.for file in config.guess config.sub
	@${RM} -f ${WRKSRC}/${file} && ${TOUCH} ${WRKSRC}/${file}
.endfor

post-install:
	@${MKDIR} ${PREFIX}/share/gnome/apps/Internet
	${INSTALL_DATA} ${WRKSRC}/share/GTelnet.desktop \
		${PREFIX}/share/gnome/apps/Internet
	@${MKDIR} ${PREFIX}/share/gnome/pixmaps
	${INSTALL_DATA} ${WRKSRC}/share/*.png \
		${PREFIX}/share/gnome/pixmaps
	@${MKDIR} ${PREFIX}/share/gnome/pixmaps/gnome-telnet
	${INSTALL_DATA} ${WRKSRC}/share/*.jpg \
		${PREFIX}/share/gnome/pixmaps/gnome-telnet

.include <bsd.port.mk>
