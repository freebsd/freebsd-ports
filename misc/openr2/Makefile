PORTNAME=	openr2
PORTVERSION=	1.3.3
PORTREVISION=	1
CATEGORIES=	misc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MFC/R2 call setup library
WWW=		https://libopenr2.org/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

BUILD_DEPENDS=	${LOCALBASE}/include/dahdi/user.h:misc/dahdi

USE_GITHUB=	yes
GH_ACCOUNT=	moises-silva
GH_TAGNAME=	d6a5716

USES=		libtool localbase
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/r2proto.conf \
		${STAGEDIR}${PREFIX}/etc/r2proto.conf.sample
	${MV} ${STAGEDIR}${PREFIX}/etc/r2test.conf \
		${STAGEDIR}${PREFIX}/etc/r2test.conf.sample

.include <bsd.port.mk>
