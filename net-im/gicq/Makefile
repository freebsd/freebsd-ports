# New ports collection makefile for:	gicq
# Date Created:				31 Oct 1998
# Whom:					Seiichirou Hiraoka
#
# $FreeBSD$
#

PORTNAME=	gicq
PORTVERSION=	0.33
PORTREVISION=	7
CATEGORIES=	net-im
MASTER_SITES=	http://download.sourceforge.net/gicq/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	flathill

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK based ICQ program

LIB_DEPENDS=	icq.0:${PORTSDIR}/net-im/libicq

USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gtk12 gnomehack gnomeprefix
WANT_GNOME=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgnomelibs}!=""
USE_GNOME+=	gnomelibs
PKGNAMESUFFIX=	-gnome
.else
CONFIGURE_ARGS+=--without-gnome
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g ; \
		 s|USE_INCLUDED_LIBINTL=yes|#USE_INCLUDED_LIBINTL=yes|g ; \
		 s|\$$\(top_builddir\)/intl/libintl.a|-lintl|g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
