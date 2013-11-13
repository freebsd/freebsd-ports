# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	fur
PORTVERSION=	0.4.6
CATEGORIES=	sysutils palm
MASTER_SITES=	SF/synce/FUR/${PORTVERSION}
PKGNAMEPREFIX=	fusefs-
DISTNAME=	FUR-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FUSE-based filesystem for Windows CE based devices

LIB_DEPENDS=	librapi.so:${PORTSDIR}/palm/synce-librapi2

OPTIONS_DEFINE=	VCHMOD
OPTIONS_DEFAULT=	VCHMOD
VCHMOD_DESC=	Fake hook for chmod that just returns 0

GNU_CONFIGURE=	yes
USES=		fuse pkgconfig iconv gmake
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include -DFUSE_USE_VERSION=26

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MVCHMOD}
CONFIGURE_ARGS+=	--enable-void-chmod
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Fur ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
