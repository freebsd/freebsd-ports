# New ports collection makefile for:	amyc
# Date Created:				10 June 2001
# Whom:					Pete Fritchman <petef@databits.net>
#
# $FreeBSD$
#

PORTNAME=	amyc
PORTVERSION=	0.9.159
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://www.crevola.com/about/current/

MAINTAINER=	petef@FreeBSD.org

LIB_DEPENDS=	intl.2:${PORTSDIR}/devel/gettext

USE_AUTOCONF=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		CFLAGS="${CFLAGS} -I${LOCALBASE}/include"

WANT_GTK=	yes

.include <bsd.port.pre.mk>

.if defined(HAVE_GTK)
PLIST_SUB=	WITH_GTK=""
USE_GTK=	yes
.else
PLIST_SUB=	WITH_GTK="@comment "
.endif

post-patch:
	@${PERL} -pi -e 's!\(datadir\)/locale!(prefix)/share/locale!' \
		${WRKSRC}/po/Makefile.in.in

.include <bsd.port.post.mk>
