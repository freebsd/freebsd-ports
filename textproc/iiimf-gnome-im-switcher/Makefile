# New ports collection makefile for:	iiimf-gnome-im-switcher
# Date created:		10 Sep 2004
# Whom:			Kuang-che Wu <kcwu@csie.org>
#
# $FreeBSD$
#

PORTNAME=	gnome-im-switcher
PORTVERSION=	${IIIMF_VER:S/_/./g:C/-.*//}
CATEGORIES=	textproc
MASTER_SITES=	http://www.openi18n.org/download/im-sdk/src/
PKGNAMEPREFIX=	iiimf-
DISTNAME=	im-sdk
DISTFILES=	${DISTNAME}-src-${IIIMF_VER}.tgz

MAINTAINER=	kcwu@csie.org
COMMENT=	IIIMF gnome input method switcher

IIIMF_VER=	r12_0_1-svn1891
WRKSRC=		${WRKDIR}/${DISTNAME}-${IIIMF_VER}/gnome-im-switcher
USE_GNOME=	gconf2 libglade2 libgnomeui gnomepanel gnomehack
USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_AUTOCONF_VER=	259
USE_AUTOHEADER_VER=	259
USE_AUTOMAKE_VER=	19
USE_LIBTOOL_VER=	15
AUTOMAKE_ARGS=	--add-missing --copy --gnu
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

post-patch:
	${REINPLACE_CMD} -e "s,/usr/lib/im,${PREFIX}/lib/im,g" \
		${WRKSRC}/../acfiles/im_common.m4
	${FIND} ${WRKSRC} -name "Makefile.am*" | ${XARGS} ${REINPLACE_CMD} -e \
		's|[(]GNOME_datadir[)]/gnome/|(datadir)/|g ; \
		s|[(]GNOME_datadir[)]/locale|(prefix)/share/locale|g ; \
		s|[(]datadir[)]/locale|(prefix)/share/locale|g ; \
		s|[(]libdir[)]/locale|(prefix)/share/locale|g ; \
		s|[(]gnomedatadir[)]/gnome|(gnomedatadir)|g ; \
		s|[(]datadir[)]/aclocal|(prefix)/share/aclocal|g ; \
		s|[(]datadir[)]/gnome/|(datadir)/|g ; \
		s|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g ; \
		s|[$$][(]localstatedir[)]/scrollkeeper|${SCROLLKEEPER_DIR}|g ; \
		s|[(]libdir[)]/bonobo/servers|(prefix)/libdata/bonobo/servers|g'

pre-configure:
	cd ${WRKSRC} && glib-gettextize --force --copy
	cd ${WRKSRC} && intltoolize --copy --force --automake
	cd ${WRKSRC} && ${LIBTOOLIZE} --force --copy
	cd ${WRKSRC} && ${ACLOCAL} -I ${LOCALBASE}/share/aclocal -I ../acfiles
	${TOUCH} ${WRKSRC}/config.h.in

.include <bsd.port.mk>
