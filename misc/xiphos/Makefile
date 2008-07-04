# New ports collection makefile for: gnomesword
# Date created:   April 27, 2007
# Whom:           Thomas Abthorpe <thomas@goodking.ca>
#
# $FreeBSD$
#

PORTNAME=	gnomesword
PORTVERSION=	2.3.5
CATEGORIES=	misc gnome
MASTER_SITES=	SF

MAINTAINER=	tabthorpe@FreeBSD.org
COMMENT=	A bible interface utilizing the sword framework

RUN_DEPENDS=	${LOCALBASE}/lib/gnome-spell/libgnome-spell-component-0.3.so:${PORTSDIR}/textproc/gnome-spell \
		${LOCALBASE}/lib/libsword-1.5.11.so:${PORTSDIR}/misc/sword
BUILD_DEPENDS=	${RUN_DEPENDS}

USE_GETTEXT=	yes
INSTALLS_OMF=	yes
USE_GNOME=	gnomehack gnomeprefix gnometarget gal2 gtkhtml3 gnomelibs intlhack gnomedocutils
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS+=	--enable-gtkhtml --enable-exporter

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS ChangeLog INSTALL NEWS README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
