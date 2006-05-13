# ex:ts=8
# New ports collection makefile for:	gxmlviewer
# Date created:			Nov 8, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gxmlviewer
PORTVERSION=	1.3.3
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An xmlviewer with a netscape plugin, and now a bonobo control as well

USE_X_PREFIX=	yes
USE_GNOME=	bonobo gnomehack gnomelibs gnomeprefix libxml2
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libiconv-prefix="${LOCALBASE}"

post-patch:
	@${REINPLACE_CMD} -e 's|intl||g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|= -DXP_UNIX|= -fPIC -DXP_UNIX|g ; \
		s|/netscape/|/gxmlviewer/|g' ${WRKSRC}/src/nsplugin/Makefile.in

post-install:
	@${MKDIR} ${X11BASE}/lib/browser_plugins
	@${LN} -sf ${PREFIX}/lib/gxmlviewer/plugins/npgxmlviewer.so \
		${X11BASE}/lib/browser_plugins/npgxmlviewer.so

.include <bsd.port.mk>
