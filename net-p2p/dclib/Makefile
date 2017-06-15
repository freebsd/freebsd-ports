# Created by: Sverrir Valgeirsson <e96sv@yahoo.se> and
# $FreeBSD$

PORTNAME=	dclib
PORTVERSION=	0.3.23
PORTREVISION=	5
CATEGORIES=	net-p2p
MASTER_SITES=	SF/wxdcgui/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Direct connect interface library for valknut

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

WRKSRC=		${WRKDIR}/${DISTNAME}

USES=		jpeg libtool localbase pathfix ssl tar:bzip2
GNU_CONFIGURE=	yes
USE_GNOME=	libxml2
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} \
		${REINPLACE_CMD} -e 's|dclib-0.3/||g'
	@${REINPLACE_CMD} -e 's|-0.3||g' ${WRKSRC}/dclib.pc.in
	@${REINPLACE_CMD} -e 's|-D_XOPEN_SOURCE=500||g; \
		s|-D_BSD_SOURCE||g' ${WRKSRC}/configure

.include <bsd.port.mk>
