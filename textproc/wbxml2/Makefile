# New ports collection makefile for:	wbxml
# Date created:			Nov 04, 2005
# Whom:				Clemens Zauner <czauner+ports@onlineloop.com>
#
# $FreeBSD$
#

PORTNAME=	wbxml2
PORTVERSION=	0.9.0
PORTREVISION=	2
CATEGORIES=	textproc devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://czauner.onlineloop.com/pub/FreeBSD/distfiles/
MASTER_SITE_SUBDIR=	wbxmllib
DISTNAME=	wbxml2-0.9.0-src

MAINTAINER=	czauner+ports@onlineloop.com
COMMENT=	Library & tools for converting wbxml<->xml

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2

WRKSRC=			${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_AUTOTOOLS=	automake:19 autoconf:259 libtool:15
AUTOMAKE_ARGS=		-acf
GNU_CONFIGURE=		yes
INSTALLS_SHLIB=		yes
CONFIGURE_ENV=		CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
			LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib -lexpat"

post-patch:
	${REINPLACE_CMD} "s,^CFLAGS,AM_CFLAGS," ${WRKSRC}/src/Makefile.am \
		${WRKSRC}/Makefile.am ${WRKSRC}/tools/Makefile.am

pre-configure:
	cd ${WRKSRC} && \
		${LIBTOOLIZE} --force --copy && \
		${ACLOCAL} -I ${LOCALBASE}/share/aclocal && \
		${AUTOHEADER} && \
		${AUTOMAKE} --add-missing && \
		${AUTOCONF}

.include <bsd.port.mk>
