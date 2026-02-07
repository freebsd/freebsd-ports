PORTNAME=	dclib
PORTVERSION=	0.3.23
PORTREVISION=	9
CATEGORIES=	net-p2p
MASTER_SITES=	SF/wxdcgui/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Direct connect interface library for valknut
WWW=		https://wxdcgui.sourceforge.net/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gnome jpeg libtool localbase pathfix ssl tar:bzip2
USE_CXXSTD=	c++14
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

WRKSRC=		${WRKDIR}/${DISTNAME}

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} \
		${REINPLACE_CMD} -e 's|dclib-0.3/||g'
	@${REINPLACE_CMD} -e 's|-0.3||g' ${WRKSRC}/dclib.pc.in
	@${REINPLACE_CMD} -e 's|-D_XOPEN_SOURCE=500||g; \
		s|-D_BSD_SOURCE||g' ${WRKSRC}/configure

.include <bsd.port.mk>
