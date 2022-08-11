PORTNAME=	libtubo
PORTVERSION=	5.0.14
CATEGORIES=	x11-fm
MASTER_SITES=	SF/xffm/libtubo/
DISTNAME=	${PORTNAME}0-${PORTVERSION}

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	XFFM Interprocess Communication and Control

LICENSE=	GPLv3

OPTIONS_DEFINE=	DOCS

USES=		gmake libtool:keepla pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-PACKAGE=no
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

WRKSRC=	${WRKDIR}/${PORTNAME}0-${PORTVERSION}

.include <bsd.port.mk>
