# New ports collection makefile for:	etherape
# Date created:				4 April 2001
# Whom: 				Holger Lamm <holger@eit.uni-kl.de>
#
# $FreeBSD$
#

PORTNAME=	etherape
PORTVERSION=	0.7.8
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	petef@databits.net

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext \
		gdk_pixbuf.2:${PORTSDIR}/x11/gnome

GNU_CONFIGURE=	yes
USE_GNOME=	yes
USE_X_PREFIX=	yes

MAN1=		etherape.1

post-patch:
	@${PERL} -pi -e 's!^confdir = .*!confdir = ${PREFIX}/share/etherape!' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
