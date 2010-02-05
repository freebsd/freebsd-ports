# Ports collection Makefile for:	epiphany-extensions
# Date created:				30 December 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/www/epiphany-extensions/Makefile,v 1.122 2009/10/19 02:40:50 kwm Exp $
#

PORTNAME=	epiphany-extensions
PORTVERSION=	2.28.1
PORTREVISION=	1
CATEGORIES=	www gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A set of add-ons for the Epiphany web browser

BUILD_DEPENDS=	epiphany:${PORTSDIR}/www/epiphany
LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre \
    		webkit-1.0.13:${PORTSDIR}/www/webkit-gtk2
RUN_DEPENDS=	epiphany:${PORTSDIR}/www/epiphany

USE_GETTEXT=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack
INSTALLS_OMF=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

EPHY_EXTENSIONS=all,rss
EPHY_VERSION=	${PORTVERSION:R}

PLIST_SUB=	VERSION=${EPHY_VERSION} EPHY_VERSION=${EPHY_VERSION}

OPTIONS=	OPENSP "Enable OpenSP SGML support" off

.include <bsd.port.pre.mk>

.if defined(WITH_OPENSP)
CONFIGURE_ARGS+=	--enable-opensp=yes
.else
CONFIGURE_ARGS+=	--disable-opensp
.endif

CONFIGURE_ARGS+=--with-extensions="${EPHY_EXTENSIONS}"

pre-everything::
	@${ECHO_MSG} "Epiphany-extensions also supports the following tunable option(s):"
	@${ECHO_MSG} "	WITH_OPENSP=yes		Enable support for OpenSP SGML validation"
	@${ECHO_MSG} ""

.include <bsd.port.post.mk>
