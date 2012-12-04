# Created by: Manuel Creach <manuel.creach@icloud.com>
# $FreeBSD$

PORTNAME=	libcec
PORTVERSION=	2.0.4
CATEGORIES=	multimedia

MAINTAINER=	manuel.creach@icloud.com
COMMENT=	Library to control Pulse-Eight's HDMI-CEC adapter

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	Pulse-Eight
GH_COMMIT=	178d498
GH_TAGNAME=	${PORTNAME}-${PORTVERSION}

USE_GMAKE=	yes
USE_AUTORECONF=	yes
USE_AUTOTOOLS=	aclocal autoheader automake autoconf libtoolize
ACLOCAL_ARGS=	-I.
AUTOMAKE_ARGS=	--add-missing
USE_PKGCONFIG=	build
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

CFLAGS+=	-D_FILE_OFFSET_BITS=64

post-patch:
	${REINPLACE_CMD} 's|-Werror||' \
		${WRKSRC}/configure.ac
	${REINPLACE_CMD} 's|$$(libdir)/\(pkgconfig\)|$$(prefix)/libdata/\1|' \
		${WRKSRC}/src/lib/Makefile.am

.include <bsd.port.mk>
