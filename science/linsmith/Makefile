# Created by: ijliao
# $FreeBSD$

PORTNAME=	linsmith
PORTVERSION=	0.99.24
PORTREVISION=	1
CATEGORIES=	science hamradio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Smith charting program

LICENSE=	GPLv2 # (or later)

USE_GNOME=	libgnomeui libxml2
USE_ICONV=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${CP} ${FILESDIR}/carg.c  ${WRKSRC}/src
	@${REINPLACE_CMD} -e \
		'/^Icon/s|=.*|=linsmith_icon|' ${WRKSRC}/linsmith.desktop

post-install:
	@${MKDIR} ${DESKTOPDIR}
	(cd ${WRKSRC} \
		&& ${INSTALL_DATA} linsmith.desktop ${DESKTOPDIR})
	(cd ${WRKSRC} \
		&& ${INSTALL_DATA} linsmith_icon.xpm ${PREFIX}/share/pixmaps)

.include <bsd.port.mk>
