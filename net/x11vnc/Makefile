# New ports collection makefile for:	x11vnc
# Date created:				7 June 2005
# Whom:					Loren M. Lang
#
# $FreeBSD$
#

PORTNAME=	x11vnc
PORTVERSION=	0.7.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=libvncserver

MAINTAINER=	lorenl@alzatex.com
COMMENT=	VNC server for use with real X displays

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg

USE_GNOME=	gnometarget
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		x11vnc.1
DOCS=		AUTHORS COPYING ChangeLog NEWS README README.LibVNCServer TODO

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure

.ifndef (NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
