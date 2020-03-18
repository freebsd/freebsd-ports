# Created by: Mykola Dzham <freebsd@levsha.org.ua>
# $FreeBSD$

PORTNAME=	apertium
PORTVERSION=	3.6.1
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Toolbox to build shallow-transfer machine translation systems

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_FreeBSD_11_powerpc64=	fails to configure on powerpc64 elfv1: *** unable to locate pcrecpp library ***
BROKEN_FreeBSD_12_powerpc64=	fails to configure on powerpc64 elfv1: *** unable to locate pcrecpp library ***

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	liblttoolbox3.so:textproc/lttoolbox \
		libpcre.so:devel/pcre
RUN_DEPENDS=	bash:shells/bash

USES=		autoreconf gmake gnome libtool localbase:ldflags pathfix pkgconfig python shebangfix
USE_GITHUB=	yes
USE_GNOME=	libxml2 libxslt
USE_LDCONFIG=	yes

GH_ACCOUNT=	unhammer:contrib
GH_PROJECT=	apertium-get:contrib
GH_TAGNAME=	2ed405e:contrib
GH_SUBDIR=	apertium/apertium-get:contrib

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
MAKE_JOBS_UNSAFE=	yes
SHEBANG_FILES=	scripts/apertium-genvldix scripts/apertium-translate-to-default-equivalent.in \
		scripts/apertium-metalrx scripts/apertium-genvdix apertium/apertium-get/apertium-get \
		scripts/apertium-filter-dix.in scripts/apertium-filter-rules.in \
		scripts/apertium-metalrx-to-lrx.in scripts/apertium-genvrdix

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
