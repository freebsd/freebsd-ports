# Created by: Jie Gao <gaoj@cpsc.ucalgary.ca>
# $FreeBSD$

PORTNAME=	scim-table-imengine
PORTVERSION=	0.5.10
PORTREVISION=	6
CATEGORIES=	textproc
MASTER_SITES=	SF/scim/scim-tables/${PORTVERSION}
DISTNAME=	scim-tables-${PORTVERSION}

MAINTAINER=	lx@FreeBSD.org
COMMENT=	SCIM table based input method engine

BUILD_DEPENDS=	scim:textproc/scim
RUN_DEPENDS=	scim:textproc/scim

GNU_CONFIGURE=	yes
USES=		compiler:c++11-lang gettext gmake libtool:keepla pkgconfig

CONFIGURE_ARGS=	--disable-skim-support
CPPFLAGS+=	-I${LOCALBASE}/include -D__STDC_ISO_10646__
LDFLAGS+=	-L${LOCALBASE}/lib -lintl

post-patch:
	@${TOUCH} ${WRKSRC}/config.h.in

.include <bsd.port.mk>
