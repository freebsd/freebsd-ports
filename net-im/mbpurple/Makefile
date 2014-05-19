# $FreeBSD$

PORTNAME=	mbpurple
PORTVERSION=	0.3.0
PORTREVISION=	3
CATEGORIES=	net-im
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PROJECTHOST=	microblog-purple

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Integrate Twitter with Pidgin (AKA microblog-purple)

BUILD_DEPENDS=	${LOCALBASE}/bin/pidgin:${PORTSDIR}/net-im/pidgin
RUN_DEPENDS=	${LOCALBASE}/bin/pidgin:${PORTSDIR}/net-im/pidgin

USES=		gmake pkgconfig
MAKE_ARGS=	PREFIX="${PREFIX}" LIBDIR="${PREFIX}/lib" \
		PURPLE_DATAROOT_DIR="${PREFIX}/share"

post-patch:
	@${REINPLACE_CMD} 's/make -C/$$(MAKE) -C/' ${WRKSRC}/Makefile

.include <bsd.port.mk>
