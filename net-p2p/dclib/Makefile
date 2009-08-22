# ex: ts=8
# New ports collection makefile for:    dclib
# Date created:                         Wed 10 Jul 2002
# Whom: Sverrir Valgeirsson <e96sv@yahoo.se> and
#	Amar Takhar <verm@drunkmonk.net> et al
#
# $FreeBSD$
#

PORTNAME=	dclib
PORTVERSION=	0.3.23
PORTREVISION=	1
CATEGORIES=	net-p2p
MASTER_SITES=	SF/wxdcgui/${PORTNAME}/${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Direct connect interface library for valknut

LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg

WRKSRC=	${WRKDIR}/${DISTNAME}

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GNOME=	libxml2

CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib

post-extract:
	${CHMOD} 0755 ${WRKSRC}/admin/install-sh

post-patch:
#	${REINPLACE_CMD} -e 's|-O2 ||g; s/-pedantic //g' \
#		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|${PREFIX}/libdata/pkgconfig|g' \
	    ${WRKSRC}/Makefile.am ${WRKSRC}/Makefile.in
	${FIND} ${WRKSRC} -name "Makefile.*" | ${XARGS} \
	    ${REINPLACE_CMD} -e 's|dclib-0.3/||g'
	${REINPLACE_CMD} -e 's|-0.3||g' ${WRKSRC}/dclib.pc.in
	${REINPLACE_CMD} -e 's|-D_XOPEN_SOURCE=500||g; \
	    s|-D_BSD_SOURCE||g' ${WRKSRC}/configure ${WRKSRC}/configure.in

.include <bsd.port.mk>
