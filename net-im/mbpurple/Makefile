# $FreeBSD$

PORTNAME=	mbpurple
PORTVERSION=	0.3.0
PORTREVISION=	3
CATEGORIES=	net-im
MASTER_SITES=	GOOGLE_CODE
PROJECTHOST=	microblog-purple

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Integrate Twitter with Pidgin (AKA microblog-purple)

BUILD_DEPENDS=	${LOCALBASE}/bin/pidgin:net-im/pidgin
RUN_DEPENDS=	${LOCALBASE}/bin/pidgin:net-im/pidgin

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake pkgconfig
MAKE_ARGS=	PREFIX="${PREFIX}" LIBDIR="${PREFIX}/lib" \
		PURPLE_DATAROOT_DIR="${PREFIX}/share"

post-patch:
	@${REINPLACE_CMD} 's/make -C/$$(MAKE) -C/' ${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/purple-2/*.so

.include <bsd.port.mk>
