# ex:ts=8
# Ports collection makefile for:	libgnomesu
# Date created:			Jan 18, 2005
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libgnomesu
PORTVERSION=	0.9.6
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://members1.chello.nl/~h.lai/libgnomesu/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A library which allows you to run programs as root or another user

USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack pkgconfig glib20 gtk20 libglade2 gconf2 \
		libgnomeui libbonobo
USE_GETTEXT=	yes
USE_PERL5_BUILD=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-pam-dir=${PREFIX}/etc/pam.d

.include <bsd.port.mk>
