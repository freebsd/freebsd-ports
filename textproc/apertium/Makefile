# Created by: Mykola Dzham <freebsd@levsha.org.ua>
# $FreeBSD$

PORTNAME=	apertium
PORTVERSION=	3.2.0
PORTREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION:R}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Toolbox to build shallow-transfer machine translation systems

LICENSE=	GPLv2 # (or later)

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash
LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre \
		liblttoolbox3.so:${PORTSDIR}/textproc/lttoolbox
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

USES=		libtool pathfix pkgconfig
USE_GNOME=	libxml2 libxslt
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
MAKE_JOBS_UNSAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB=	APVER="${PORTVERSION:R}"

post-patch:
	@${REINPLACE_CMD} -e \
		's| -ansi | | ; \
		 s| -march=.* | | ; \
		 s| -mtune=.* | | ; \
		 s| -O3 | | ; \
		 s|pcre_info|pcre_fullinfo|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|\([[:blank:]]\)\($$(modesdir)\)|\1$$(DESTDIR)\2|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|_C_|_H_|' ${WRKSRC}/apertium/tmx_aligner_tool.h

.include <bsd.port.mk>
