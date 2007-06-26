# New ports collection makefile for:    scim
# Date created:		20 May 2004
# Whom:			Jie Gao	<gaoj@cpsc.ucalgary.ca>
#
# $FreeBSD$
#

PORTNAME=	scim
PORTVERSION=	1.4.7
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=scim

MAINTAINER=	lx@FreeBSD.org
COMMENT=	Smart Common Input Method platform

USE_GNOME=	gnomehack gnomehier gtk20 intlhack

USE_AUTOTOOLS=	libtool:15
USE_XLIB=	yes
USE_ICONV=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

.include <bsd.port.pre.mk>

CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include -D__STDC_ISO_10646__" \
		LDFLAGS="-L${LOCALBASE}/lib -lintl"

post-patch:
	${REINPLACE_CMD} 's|$$(datadir)/pixmaps|$$(prefix)/share/gnome/pixmaps|' \
			${WRKSRC}/data/pixmaps/Makefile.in
	${REINPLACE_CMD} -e 's|$$(datadir)/app|$$(prefix)/share/gnome/app| ; \
		 s|$$(datadir)/control|$$(prefix)/share/gnome/control| ; \
		 /^scim_setup_LDFLAGS/s|=|= ${PTHREAD_LIBS}|' \
			${WRKSRC}/extras/setup/Makefile.in

post-install:
	@gtk-query-immodules-2.0 > ${LOCALBASE}/etc/gtk-2.0/gtk.immodules
	@${CAT} ${PKGMESSAGE}
	@${ECHO} To display this message again, type pkg_info -D ${PKGNAME}

.include <bsd.port.post.mk>
