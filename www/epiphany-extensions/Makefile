# Ports collection Makefile for:	epiphany-extensions
# Date created:				30 December 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	epiphany
PORTVERSION=	1.0
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}${PKGNAMESUFFIX}/1.0
PKGNAMESUFFIX=	-extensions
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A set of add-ons for the Epiphany web browser

BUILD_DEPENDS=	epiphany:${PORTSDIR}/www/epiphany \
		${X11BASE}/lib/${MOZILLA}/components/libwidget_gtk2.so:${PORTSDIR}/www/${MOZILLA}
RUN_DEPENDS=	epiphany:${PORTSDIR}/www/epiphany \
		${X11BASE}/lib/${MOZILLA}/components/libwidget_gtk2.so:${PORTSDIR}/www/${MOZILLA}

MOZILLA=	mozilla
HEADERS_SUFX=

MOZ_CONFIGURE_ARGS=	--with-mozilla-snapshot="1.7"

.if !defined(WITH_MOZILLA)
MOZILLA=	mozilla
HEADERS_SUFX=
.else
.if ${WITH_MOZILLA}=="mozilla-devel" || ${WITH_MOZILLA}=="mozilla-devel-gtk2"
MOZILLA=	mozilla-devel
HEADERS_SUFX=	-devel
MOZ_CONFIGURE_ARGS=	--with-mozilla-snapshot="1.8a2"
.else
MOZILLA=	mozilla
HEADERS_SUFX=
.endif
.endif

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack gnometarget
USE_LIBTOOL_VER=15
USE_GMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--with-extensions="all" \
		${MOZ_CONFIGURE_ARGS}

.if defined(PACKAGE_BUILDING) || defined(PARALLEL_PACKAGE_BUILD)
.undef WITHOUT_OPENSP
WITH_OPENSP=	yes
.endif

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libosp.so)
WITH_OPENSP=	yes
.endif

.if defined(WITH_OPENSP)
CONFIGURE_ARGS+=	--enable-opensp=yes
.else
CONFIGURE_ARGS+=	--enable-opensp=no
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} " By default epiphany-extensions builds with www/mozilla support, but you can"
	@${ECHO_MSG} " change this by defining WITH_MOZILLA to one of the following values:"
	@${ECHO_MSG}
	@${ECHO_MSG} "  mozilla-devel "
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Epiphany-extensions also supports the following tunable option(s):"
	@${ECHO_MSG} "	WITH_OPENSP=yes		Enable support for OpenSP SGML validation"
	@${ECHO_MSG} ""

post-patch:
	@${REINPLACE_CMD} -e 's|mozilla-gtkmozembed|mozilla-gtkmozembed${HEADERS_SUFX}|g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
