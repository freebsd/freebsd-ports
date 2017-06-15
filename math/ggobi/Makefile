# Created by: Rainer Hurling <rhurlin@gwdg.de>
# $FreeBSD$

PORTNAME=	ggobi
PORTVERSION=	2.1.11
PORTREVISION=	1
CATEGORIES=	math graphics
MASTER_SITES=	http://www.ggobi.org/downloads/

MAINTAINER=	rhurlin@gwdg.de
COMMENT=	Data visualization system

LICENSE=	EPL

LIB_DEPENDS=	libltdl.so:devel/libltdl

USES=		pkgconfig tar:bzip2 libtool pathfix desktop-file-utils
USE_GNOME=	gtk20 libxml2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-all-plugins

SUB_FILES=	pkg-message

ALL_TARGET=	all ggobirc
INSTALL_TARGET=	install-strip

post-build:
	@${REINPLACE_CMD} -e 's|plugin.la|plugin.so|g' ${WRKSRC}/ggobirc

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/xdg/ggobi
	${INSTALL_DATA} ${WRKSRC}/ggobirc ${STAGEDIR}${PREFIX}/etc/xdg/ggobi/ggobirc.sample

.include <bsd.port.mk>
