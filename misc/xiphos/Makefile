# New ports collection makefile for: gnomesword
# Date created:   Oct 26, 2002
# Whom:           J Shoemaker <shoemaker@softhome.net>
#
# $FreeBSD$
#

PORTNAME=	gnomesword
PORTVERSION=	2.1.1
CATEGORIES=	misc gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A bible interface utilizing the sword framework

BUILD_DEPENDS=	${X11BASE}/lib/gnome-spell/libgnome-spell-component-0.3.so:${PORTSDIR}/textproc/gnomespell
LIB_DEPENDS=	sword.4:${PORTSDIR}/misc/sword
RUN_DEPENDS=	${X11BASE}/lib/gnome-spell/libgnome-spell-component-0.3.so:${PORTSDIR}/textproc/gnomespell

USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomeprefix gnometarget gtkhtml3 intlhack
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|=share/pix|=share/gnome/pix|g ; \
		 s|=share/app|=share/gnome/app|g' ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS ChangeLog INSTALL NEWS README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
