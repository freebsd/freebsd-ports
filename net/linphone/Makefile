# New ports collection makefile for:	linphone
# Date created:				30 December 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	linphone
PORTVERSION=	0.9.1
CATEGORIES=	net
MASTER_SITES=	http://savannah.gnu.org/download/linphone/${PORTVERSION}/sources/

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	osip.0:${PORTSDIR}/net/libosip

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomehack gnomeprefix libpanel
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		speexdec.1 speexenc.1

.include <bsd.port.mk>
