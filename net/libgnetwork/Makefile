# New ports collection makefile for:	libgnetwork
# Date created:				11 December 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libgnetwork
PORTVERSION=	0.0.4
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.0
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A GLib-based networking wrapper

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack gconf2
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"
LDFLAGS+=	-L${LOCALBASE}/lib

.if !defined(WITHOUT_SSL)
LIB_DEPENDS+=	gnutls.7:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=--enable-ssl=gnutls
.else
CONFIGURE_ARGS+=--enable-ssl=no
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "libgnetwork has the following configurable option(s):"
	@${ECHO_MSG} "	WITHOUT_SSL	Disable GnuTLS SSL support"
	@${ECHO_MSG} ""

post-patch:
	@${FIND} ${WRKSRC} -name "intltool-merge.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|mkdir $$lang or|mkdir $$lang, 0777 or| ; \
		 s|^push @INC, "/.*|push @INC, "${LOCALBASE}/share/intltool";|'

.include <bsd.port.mk>
