# Created by: Leland Wang <llwang@infor.org>
# $FreeBSD$

PORTNAME=	scim-openvanilla
PORTVERSION=	0.7.2.20070514
PORTREVISION=	11
CATEGORIES=	textproc
MASTER_SITES=	LOCAL/rafan
DISTNAME=	openvanilla-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SCIM OpenVanilla input method (IM)/output filter (OF) framework

BUILD_DEPENDS=	scim:textproc/scim	\
		${LOCALBASE}/include/OpenVanilla/OpenVanilla.h:textproc/openvanilla-framework
RUN_DEPENDS=	scim:textproc/scim
LIB_DEPENDS=	libltdl.so:devel/libltdl \
		libexpat.so:textproc/expat2

WRKSRC=		${WRKDIR}/${DISTNAME}/Loaders/SCIM
USES=		pkgconfig gettext iconv gmake libtool:keepla
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	OV_MODULEDIR=${PREFIX}/lib/openvanilla/
CPPFLAGS+=	-I${LOCALBASE}/include
INSTALL_TARGET=	install-strip

PLIST_FILES=	lib/scim-1.0/1.4.0/IMEngine/OVLoader-SCIM.a	\
		lib/scim-1.0/1.4.0/IMEngine/OVLoader-SCIM.la	\
		lib/scim-1.0/1.4.0/IMEngine/OVLoader-SCIM.so

.include <bsd.port.mk>
