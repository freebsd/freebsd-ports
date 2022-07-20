PORTNAME=	libnfs
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	5.0.1
CATEGORIES=	net

MAINTAINER=	snoe925@gmail.com
COMMENT=	Client library for accessing NFS shares over a network

LICENSE=	GPLv3 LGPL21
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf gmake libtool pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	sahlberg
USE_LDCONFIG=	yes

SHLIB=		14
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-werror

PLIST_SUB=	SHLIB=${SHLIB}

post-patch:
	${REINPLACE_CMD} 's|$$(libdir)/\(pkgconfig\)|$$(prefix)/libdata/\1|' \
		${WRKSRC}/Makefile.am

.include <bsd.port.mk>
