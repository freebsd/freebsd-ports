# New ports collection makefile for:	libgringotts
# Date created:				23 November 2002
# Whom:					Anders Nordby <anders@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libgringotts
PORTVERSION=	1.1.1
CATEGORIES=	security
MASTER_SITES=	http://devel.pluto.linux.it/projects/libGringotts/current/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/

MAINTAINER=	anders@FreeBSD.org

LIB_DEPENDS=	mcrypt.7:${PORTSDIR}/security/libmcrypt \
		mhash.2:${PORTSDIR}/security/mhash

USE_BZIP2=	yes
USE_LIBTOOL=	yes
USE_REINPLACE=	yes
CONFIGURE_ENV+=	LIBS="-L${LOCALBASE}/lib" CPPFLAGS="-I${LOCALBASE}/include"
CONFIGURE_ARGS+=	--with-pkg-config-files=${PREFIX}/libdata/pkgconfig
INSTALLS_SHLIB=	yes

post-patch:
	${REINPLACE_CMD} -e "s|md5sum|md5|g" ${WRKSRC}/Makefile.in

pre-install:
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -E "s|^(SUBDIRS =.*) docs|\1|" ${WRKSRC}/Makefile
.else
	${REINPLACE_CMD} -E "s|^(documentationdir = .*/libgringotts)-.*|\1|" \
		${WRKSRC}/docs/Makefile
.endif

.include <bsd.port.mk>
