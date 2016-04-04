# Created by: Yuri Victorovich <yuri@tsoft.com>
# $FreeBSD$

PORTNAME=	timbl
PORTVERSION=	6.4.2
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	http://ilk.uvt.nl/downloads/pub/software/

MAINTAINER=	yuri@tsoft.com
COMMENT=	Tilburg Memory Based Learner

LIB_DEPENDS=	libxml2.so:textproc/libxml2

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		gmake libtool pathfix pkgconfig
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} 's#doc/@PACKAGE@/examples#examples/@PACKAGE@#' ${WRKSRC}/demos/Makefile.in

.include <bsd.port.mk>
