# Created by: Anders Nordby <anders@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libgringotts
PORTVERSION=	1.2.1
CATEGORIES=	security
MASTER_SITES=	BERLIOS
MASTER_SITE_SUBDIR=	gringotts

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for encapsulating/safekeeping data in encrypted/compressed form

LIB_DEPENDS=	mcrypt.8:${PORTSDIR}/security/libmcrypt \
		mhash.2:${PORTSDIR}/security/mhash

OPTIONS_DEFINE=		DOCS

USE_AUTOTOOLS=	libtool
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS+=	--with-pkg-config-files=${PREFIX}/libdata/pkgconfig
USE_LDCONFIG=	yes

post-patch:
	${REINPLACE_CMD} -e "s|md5sum|md5|g" ${WRKSRC}/Makefile.in

pre-install:
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -E -e "s|^(SUBDIRS =.*) docs|\1|" ${WRKSRC}/Makefile
	${REINPLACE_CMD} -E -e "s|^(install-data-am:.*)install-libgringottsdocDATA|\1|" ${WRKSRC}/Makefile
.else
	${REINPLACE_CMD} -E "s|^(libgringottsdocdir =).*|\1 $$\(datadir\)/doc/libgringotts|" ${WRKSRC}/docs/Makefile ${WRKSRC}/Makefile
.endif

.include <bsd.port.mk>
