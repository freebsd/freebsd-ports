# Created by: Manuel Creach <manuel.creach@icloud.com>
# $FreeBSD$

PORTNAME=	libcec
PORTVERSION=	2.0.2
CATEGORIES=	multimedia
MASTER_SITES=	https://github.com/Pulse-Eight/libcec/zipball/libcec-2.0.2/

MAINTAINER=	manuel.creach@icloud.com
COMMENT=	Library that allows you to use the Pulse-Eight's HDMI-CEC Adapter

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

FETCH_ARGS=	-Fpr

USE_GMAKE=	yes
USE_AUTORECONF=	yes
USE_AUTOTOOLS=	aclocal autoheader automake autoconf libtoolize
ACLOCAL_ARGS=	-I.
AUTOMAKE_ARGS=	--add-missing
USE_PKGCONFIG=	build
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

CFLAGS+=	-D_FILE_OFFSET_BITS=64

WRKSRC=		${WRKDIR}/Pulse-Eight-libcec-a9ac151

post-patch:
	${REINPLACE_CMD} 's|-Werror||' \
		${WRKSRC}/configure.ac
	${REINPLACE_CMD} 's|$$(libdir)/\(pkgconfig\)|$$(prefix)/libdata/\1|' \
		${WRKSRC}/src/lib/Makefile.am

.include <bsd.port.mk>
