# Created by: Sverrir Valgeirsson <e96sv@yahoo.se> and 
# $FreeBSD$

PORTNAME=	dclib
PORTVERSION=	0.3.23
PORTREVISION=	5
CATEGORIES=	net-p2p
MASTER_SITES=	SF/wxdcgui/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Direct connect interface library for valknut

WRKSRC=	${WRKDIR}/${DISTNAME}

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		jpeg libtool pathfix tar:bzip2
USE_GNOME=	libxml2
USE_LDCONFIG=	yes
USE_OPENSSL=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if ${OSVERSION} >= 1000015
EXTRA_PATCHES=	${FILESDIR}/extra-dclib-core_cssl.cpp
.endif

post-patch:
	${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} \
	    ${REINPLACE_CMD} -e 's|dclib-0.3/||g'
	${REINPLACE_CMD} -e 's|-0.3||g' ${WRKSRC}/dclib.pc.in
	${REINPLACE_CMD} -e 's|-D_XOPEN_SOURCE=500||g; \
	    s|-D_BSD_SOURCE||g' ${WRKSRC}/configure

.include <bsd.port.mk>
