# ex:ts=8
# New ports collection makefile for:	gfontview
# Date created:			Jul 9, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gfontview
PORTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	print gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	t1.4:${PORTSDIR}/devel/t1lib

USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_GNOME=	yes
USE_FREETYPE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include/freetype1/freetype \
			  -I${LOCALBASE}/include" \
		SPOOLER="/usr/bin/lpr" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-fontdir="${LOCALBASE}/share/ghostscript/fonts" \
		--with-libungif

post-patch:
	@${REINPLACE_CMD} -e 's|CXXFLAGS="-O2"|CXXFLAGS="$$CXXFLAGS"|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g ; \
		 s|USE_INCLUDED_LIBINTL=yes|#USE_INCLUDED_LIBINTL=yes|g ; \
		 s|\$$(top_builddir)/intl/libintl.a|-lintl|g' \
			${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|\$$(datadir)/gnome/|$$(datadir)/|g ; \
		 s|\$$(datadir)/locale|$$(prefix)/share/locale|g ; \
		 s|-I/usr/include/freetype||g' \
			${WRKSRC}/Makefile.in

.include <bsd.port.mk>
