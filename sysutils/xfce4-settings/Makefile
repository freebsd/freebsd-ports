# New ports collection makefile for:	xfce4-settings
# Date created:		2 October 2008
# Whom:			Oliver Lehmann <oliver@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xfce4-settings
PORTVERSION=	4.6.1
PORTREVISION=	1
CATEGORIES=	sysutils xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
DIST_SUBDIR=	xfce4

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	XFce 4 settings application

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser
LIB_DEPENDS=	wnck-1.22:${PORTSDIR}/x11-toolkits/libwnck

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget gtk20 intltool intlhack pkgconfig
USE_XFCE=	configenv libexo libgui libutil xfconf

post-patch:
	# until xfce4-icon-theme is back we rely on Tango
	@${REINPLACE_CMD} -e 's|Rodent|Tango|g' \
		${WRKSRC}/dialogs/appearance-settings/main.c \
		${WRKSRC}/xfsettingsd/xsettings.xml
.include <bsd.port.mk>
