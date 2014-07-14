# Created by: Leland Wang <llwang@infor.org>
# $FreeBSD$

PORTNAME=	scim-openvanilla
PORTVERSION=	0.7.2.20070514
PORTREVISION=	7
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	rafan
DISTNAME=	openvanilla-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SCIM OpenVanilla input method (IM)/output filter (OF) framework

BUILD_DEPENDS=	scim:${PORTSDIR}/textproc/scim	\
		${LOCALBASE}/include/OpenVanilla/OpenVanilla.h:${PORTSDIR}/textproc/openvanilla-framework
RUN_DEPENDS=	scim:${PORTSDIR}/textproc/scim
LIB_DEPENDS=	libexpat.so:${PORTSDIR}/textproc/expat2

USE_AUTOTOOLS=	libltdl
WRKSRC=		${WRKDIR}/${DISTNAME}/Loaders/SCIM
USES=		pkgconfig gettext iconv gmake
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	OV_MODULEDIR=${PREFIX}/lib/openvanilla/
CPPFLAGS+=	-I${LOCALBASE}/include

PLIST_FILES=	lib/scim-1.0/1.4.0/IMEngine/OVLoader-SCIM.a	\
		lib/scim-1.0/1.4.0/IMEngine/OVLoader-SCIM.la	\
		lib/scim-1.0/1.4.0/IMEngine/OVLoader-SCIM.so

NO_STAGE=	yes
.include <bsd.port.mk>
