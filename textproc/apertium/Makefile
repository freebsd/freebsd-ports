# Created by: Mykola Dzham <freebsd@levsha.org.ua>
# $FreeBSD$

PORTNAME=	apertium
PORTVERSION=	3.4.0
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION:R}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Toolbox to build shallow-transfer machine translation systems

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	liblttoolbox3.so:textproc/lttoolbox \
		libpcre.so:devel/pcre
RUN_DEPENDS=	bash:shells/bash

USES=		autoreconf pathfix pkgconfig libtool
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
		'/^AM_INIT_AUTOMAKE/s|(.*)|()| ; \
		 s| -ansi | | ; \
		 s| -march=.* | | ; \
		 s| -mtune=.* | | ; \
		 s| -O3 | |' \
		${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e \
		's|^INCLUDES |AM_CPPFLAGS | ; \
		 s|-lapertium$$(.*)|libapertium3.la|' \
		${WRKSRC}/apertium/Makefile.am
	@${REINPLACE_CMD} -e \
		's|_C_|_H_|' \
		${WRKSRC}/apertium/tmx_aligner_tool.h

.include <bsd.port.mk>
