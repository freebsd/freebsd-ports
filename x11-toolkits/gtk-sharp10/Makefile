# Created by: Juli Mallett
# $FreeBSD$

PORTNAME=	gtk-sharp
PORTVERSION=	1.0.10
PORTREVISION=	21
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://ftp.novell.com/pub/mono/sources/${PORTNAME}/
PKGNAMESUFFIX=	10

MAINTAINER=	mono@FreeBSD.org
COMMENT=	GTK+ and GNOME interfaces for the .NET runtime

BUILD_DEPENDS=	mono:${PORTSDIR}/lang/mono
RUN_DEPENDS=	mono:${PORTSDIR}/lang/mono

LATEST_LINK=	gtk-sharp10
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		gmake pathfix perl5 pkgconfig
USE_PERL5=	run
USE_GNOME=	gtkhtml3 vte librsvg2 libgnomecanvas \
		libgnomeprintui libglade2 libgnomeui
MAKE_ENV=	INSTALL_STRIP_FLAG=${STRIP}
USE_AUTOTOOLS=	libtool

post-patch:
	@${FIND} ${WRKSRC} -name '*.pl' -o -name 'gapi-parser' | ${XARGS} \
	    	${REINPLACE_CMD} -e 's|^#!/usr/bin/perl|#!${PERL}|'
	@${REINPLACE_CMD} -e 's|enable_gda=yes|enable_gda=no|g ; \
		s|enable_gnomedb=yes|enable_gnomedb=no|g ; \
		s|libgtkhtml-3.8|libgtkhtml-3.14|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|glib/.*\.h>|glib.h>|g' \
		${WRKSRC}/glib/glue/slist.c ${WRKSRC}/glib/glue/list.c

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.mk>
