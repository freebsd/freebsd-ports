PORTNAME=	libtubo
PORTVERSION=	5.0.14
PORTREVISION=	1
CATEGORIES=	x11-fm
MASTER_SITES=	SF/xffm/libtubo/
DISTNAME=	${PORTNAME}0-${PORTVERSION}

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	XFFM Interprocess Communication and Control
WWW=		https://xffm.sourceforge.net/libtubo.html

LICENSE=	GPLv3

USES=		gmake libtool:keepla pkgconfig
USE_LDCONFIG=	yes

GNU_CONFIGURE=			yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS+=		--with-PACKAGE=no
INSTALL_TARGET=			install-strip

WRKSRC=		${WRKDIR}/${PORTNAME}0-${PORTVERSION}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
