# New ports collection makefile for:    gtk+licq
# Date created:                         17 Oct 2000
# Whom:                                 Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	gtk+licq
PORTVERSION=	0.51
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://gtk.licq.org/download/

MAINTAINER=	roman@xpert.com

BUILD_DEPENDS=	${LOCALBASE}/include/licq/licq_icqd.h:${PORTSDIR}/net/licq
LIB_DEPENDS=	pspell.15:${PORTSDIR}/textproc/aspell \
		iconv.3:${PORTSDIR}/converters/libiconv
RUN_DEPENDS=	licq:${PORTSDIR}/net/licq

BROKEN=		'does not support licq >= 1.2.0'

# It breaks the build for some reason
#USE_LIBTOOL=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mlibcapplet}!=""
USE_GNOME+=	libcapplet
PKGNAMESUFFIX=	-gnome
CONFIGURE_ARGS+=	--enable-gnome
.else
CONFIGURE_ARGS+=	--disable-gnome
.endif

post-patch:
	@find ${WRKSRC} -name "Makefile.in*" | xargs ${PERL5} -pi -e \
		's|-D_REENTRANT|${PTHREAD_CFLAGS} -D_REENTRANT|g ; \
		s|^localedir =.*|localedir = \$$(prefix)/share/locale| ; \
		s|^gtklicq_helpdir =.*|gtklicq_helpdir = \
		\$$(datadir)/help/gtk+licq/C|'
.if !defined(HAVE_GNOME)
	@${PERL5} -pi -e \
		's|^SUBDIRS =.*|SUBDIRS =|' ${WRKSRC}/doc/Makefile.in
	@${PERL5} -pi -e \
		's|\sinstall-menuDATA||;s|\sinstall-ximianmenuDATA||' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.post.mk>
