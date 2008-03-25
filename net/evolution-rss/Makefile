# New ports collection makefile for:	evolution-rss
# Date created:		2007-09-21
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/net/evolution-rss/Makefile,v 1.2 2007/10/11 12:35:05 ahze Exp $

PORTNAME=	evolution-rss
PORTVERSION=	0.0.8
CATEGORIES=	net gnome
MASTER_SITES=	http://gnome.eu.org/

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	RSS Feeds support for evolution mail

BUILD_DEPENDS=	evolution:${PORTSDIR}/mail/evolution
RUN_DEPENDS=	evolution:${PORTSDIR}/mail/evolution

USE_GECKO=	firefox
USE_GNOME=	intltool
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
GCONF_SCHEMAS=	evolution-rss.schemas
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
USE_GETTEXT=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|@serverdir@|${PREFIX}/libdata/bonobo/servers|' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/mozilla/bsd.gecko.mk"
.include <bsd.port.post.mk>
