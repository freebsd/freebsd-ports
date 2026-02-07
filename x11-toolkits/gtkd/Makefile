PORTNAME=	gtkd
PORTVERSION=	3.10.0
PORTREVISION=	4
CATEGORIES=	x11-toolkits
MASTER_SITES=	https://gtkd.org/Downloads/sources/
DISTNAME=	GtkD-${PORTVERSION}

MAINTAINER=	romain@FreeBSD.org
COMMENT=	D binding and OO wrapper of GTK
WWW=		https://gtkd.org/index.html

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	ldc2:lang/ldc

USES=		gmake zip
WRKSRC=		${WRKDIR}
MAKEFILE=	GNUmakefile
# avoid building demos
ALL_TARGET=	libs shared-libs

SSP_UNSAFE=	ldc2 does not support -fstack-protector-strong

post-patch:
	${REINPLACE_CMD} -e 's:\$$(libdir)/pkgconfig:libdata/pkgconfig:' \
		${WRKSRC}/${MAKEFILE}

.include <bsd.port.mk>
