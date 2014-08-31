# Created by: Mykola Dzham <freebsd@levsha.org.ua>
# $FreeBSD$

PORTNAME=	apertium
PORTVERSION=	3.3.0
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION:R}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Toolbox to build shallow-transfer machine translation systems

LICENSE=	GPLv2 # (or later)

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash
LIB_DEPENDS=	liblttoolbox3.so:${PORTSDIR}/textproc/lttoolbox \
		libpcre.so:${PORTSDIR}/devel/pcre
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

USES=		pathfix pkgconfig libtool
USE_GNOME=	libxml2 libxslt
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
MAKE_JOBS_UNSAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB=	APVER="${PORTVERSION:R}"

post-patch:
	
	@${REINPLACE_CMD} -e 's/pcre_info/pcre_fullinfo/g' ${WRKSRC}/configure

.include <bsd.port.mk>
