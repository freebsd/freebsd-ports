# New ports collection makefile for:    gtk+licq
# Date created:                         17 Oct 2000
# Whom:                                 Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	gtk+licq
PORTVERSION=	0.50.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://gtk.licq.org/download/

MAINTAINER=	ishmael27@home.com

BUILD_DEPENDS=	${LOCALBASE}/include/licq/licq_icqd.h:${PORTSDIR}/net/licq
LIB_DEPENDS=	pspell.4:${PORTSDIR}/textproc/pspell
RUN_DEPENDS=	licq:${PORTSDIR}/net/licq

USE_GMAKE=	yes
USE_GTK=	yes
WANT_GNOME=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if defined(HAVE_GNOME)
USE_GNOME=	yes
CONFIGURE_ARGS=	--enable-gnome
.else
CONFIGURE_ARGS=	--disable-gnome
post-patch:
	@${PERL5} -pi -e \
		's|^SUBDIRS\ =.*|SUBDIRS\ =\ |' ${WRKSRC}/doc/Makefile.in
.endif

post-configure:
	@${PERL5} -pi -e \
		's|^deplibs_check_method=.*|deplibs_check_method=pass_all|' \
		${WRKSRC}/libtool

.include <bsd.port.post.mk>
