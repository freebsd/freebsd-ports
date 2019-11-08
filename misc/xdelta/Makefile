# Created by: jmacd
# $FreeBSD$

PORTNAME=	xdelta
PORTVERSION=	1.1.4
PORTREVISION=	5
CATEGORIES=	misc devel
MASTER_SITES=	http://www.mirrorservice.org/sites/vectorlinux.com/veclinux-6.0/source/extra/x-apps/xdelta/1.1.4/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Diff/patch utility for binary files

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gnome libtool pkgconfig
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so

.include <bsd.port.mk>
