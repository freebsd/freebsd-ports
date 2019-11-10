# Created by: Mykola Dzham <freebsd@levsha.org.ua>
# $FreeBSD$

PORTNAME=	apertium
PORTVERSION=	3.4.2
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION:R}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Toolbox to build shallow-transfer machine translation systems

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_powerpc64=	fails to configure: error: *** unable to locate pcrecpp library ***

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	liblttoolbox3.so:textproc/lttoolbox \
		libpcre.so:devel/pcre
RUN_DEPENDS=	bash:shells/bash

USES=		autoreconf compiler:c++11-lang gnome libtool localbase:ldflags \
		pathfix pkgconfig
USE_GNOME=	libxml2 libxslt
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
MAKE_JOBS_UNSAFE=	yes

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
