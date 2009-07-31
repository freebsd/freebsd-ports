# New ports collection makefile for:    scim
# Date created:		20 May 2004
# Whom:			Jie Gao	<gaoj@cpsc.ucalgary.ca>
#
# $FreeBSD$
#

PORTNAME=	scim
PORTVERSION=	1.4.7
PORTREVISION=	5
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	lx@FreeBSD.org
COMMENT=	Smart Common Input Method platform

USE_GNOME=	gnomehack gnomehier gtk20 intlhack

USE_AUTOTOOLS=	libtool:15
USE_ICONV=	yes
USE_GMAKE=	yes
USE_XORG=	x11 xpm
USE_LDCONFIG=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

.include <bsd.port.pre.mk>

CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include -D__STDC_ISO_10646__" \
		LDFLAGS="-L${LOCALBASE}/lib -lintl"

post-patch:
	${REINPLACE_CMD} -e '/^libscim@SCIM_EPOCH@_la_LDFLAGS/s|=|= ${PTHREAD_LIBS}|' \
		${WRKSRC}/src/Makefile.in

post-install:
	@gtk-query-immodules-2.0 > ${LOCALBASE}/etc/gtk-2.0/gtk.immodules
	@${CAT} ${PKGMESSAGE}
	@${ECHO} To display this message again, type ${PKG_INFO} -D ${PKGNAME}

.include <bsd.port.post.mk>
