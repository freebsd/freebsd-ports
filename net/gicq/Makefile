# New ports collection makefile for:	gicq
# Date Created:				31 Oct 1998
# Whom:					Seiichirou Hiraoka
#
# $FreeBSD$
#

PORTNAME=	gicq
PORTVERSION=	0.33
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		ftp://ftp.korsoft.com/pub/gicq/
MASTER_SITE_SUBDIR=	flathill

MAINTAINER=	flathill@FreeBSD.org

LIB_DEPENDS=	icq.0:${PORTSDIR}/net/libicq

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GNOMENG=	yes
WANT_GNOME=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgtk12}!=""
USE_GNOME+=	gtk12
PKGNAMESUFFIX=	-gtk
.else
CONFIGURE_ARGS+=--without-gnome
.endif

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g ; \
		 s|USE_INCLUDED_LIBINTL=yes|#USE_INCLUDED_LIBINTL=yes|g ; \
		 s|\$$\(top_builddir\)/intl/libintl.a|-lintl|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$$\(datadir\)/gnome/|\$$\(datadir\)/|g ; \
		 s|\$$\(datadir\)/locale|\$$\(prefix\)/share/locale|g'

.include <bsd.port.post.mk>
