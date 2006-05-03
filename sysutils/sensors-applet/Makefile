# New ports collection makefile for:	sensors-applet
# Date created:			03 May 2006
# Whom:				Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sensors-applet
PORTVERSION=	1.6.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	A GNOME applet displaying hardware sensor values

RUN_DEPENDS=	mbmon:${PORTSDIR}/sysutils/mbmon

USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomeprefix intlhack gnomepanel
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -DMBMON_EXECUTABLE=\\\"${LOCALBASE}/bin/mbmon\\\"" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${CP} -f ${FILESDIR}/mbmon-sensors-interface.* ${WRKSRC}/src

.include <bsd.port.mk>
