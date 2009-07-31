# New ports collection makefile for:	gal2
# Date created:				25 August 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11-toolkits/gal2/Makefile,v 1.54 2007/05/23 14:37:18 ahze Exp $
#

PORTNAME=	gal2
PORTVERSION=	2.5.3
PORTREVISION?=	7
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/${PORTNAME:S/2$//}/2.5
DISTNAME=	${PORTNAME:S/2$//}-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A collection of widgets taken from GNOME 2 gnumeric

USE_BZIP2=	yes

.if !defined(REFERENCE_PORT)

USE_PERL5=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix intlhack libgnomeui libgnomeprintui \
		ltverhack
USE_GETTEXT=	yes
USE_XORG=	x11
USE_LDCONFIG=	yes
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

.include <bsd.port.post.mk>

.endif
