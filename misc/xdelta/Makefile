# Created by: jmacd
# $FreeBSD$

PORTNAME=	xdelta
PORTVERSION=	1.1.4
PORTREVISION=	5
CATEGORIES=	misc devel
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Diff/patch utility for binary files

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool pkgconfig
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so

.include <bsd.port.mk>
