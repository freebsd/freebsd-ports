# New ports collection makefile for:	amyc
# Date Created:				10 June 2001
# Whom:					Pete Fritchman <petef@databits.net>
#
# $FreeBSD$
#

PORTNAME=	amyc
PORTVERSION=	0.9.159
CATEGORIES=	www
MASTER_SITES=	http://www.crevola.com/about/current/

MAINTAINER=	petef@databits.net

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext

USE_AUTOCONF=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		CFLAGS="${CFLAGS} -I${LOCALBASE}/include"

WANT_GTK=	yes

.include <bsd.port.pre.mk>

.if defined(HAVE_GTK)
PLIST_SUB=	WITH_GTK=""
.else
PLIST_SUB=	WITH_GTK="@comment "
.endif

.include <bsd.port.post.mk>
