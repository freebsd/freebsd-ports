# New ports collection makefile for:	gal2
# Date created:				25 August 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11-toolkits/gal2/Makefile,v 1.52 2005/08/19 13:26:41 marcus Exp $
#

PORTNAME=	gal2
PORTVERSION=	2.5.3
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME:S/2$//}/2.5
DISTNAME=	${PORTNAME:S/2$//}-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A collection of widgets taken from GNOME 2 gnumeric

USE_BZIP2=	yes
PREFIX?=	${X11BASE}

.if !defined(REFERENCE_PORT)

PORTREVISION=	2

USE_XLIB=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix intlhack libgnomeui libgnomeprintui \
		ltverhack
USE_GETTEXT=	yes
INSTALLS_SHLIB=	yes
USE_AUTOTOOLS=  libtool:15
CONFIGURE_ARGS=	--enable-static --with-libiconv
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

PLIST_SUB=	VERSION="2.6" PORTVERSION=${PORTVERSION} \
		SHLIBVERSION="2.4"

.include <bsd.port.pre.mk>

post-extract:
	${TOUCH} -f ${WRKSRC}/gal/util/e-util-private.h

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/ s|docs||' ${WRKSRC}/Makefile.in
.if ( ${OSVERSION} > 600000 && ${OSVERSION} < 600006 ) || \
	( ${OSVERSION} < 503101 )
.for po in da.po it.po zh_CN.po
	@${REINPLACE_CMD} -e 's|%-|%|g' ${WRKSRC}/po/${po}
.endfor
.endif

.include <bsd.port.post.mk>

.endif
