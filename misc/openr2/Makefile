PORTNAME=	openr2
PORTVERSION=	1.3.3
CATEGORIES=	misc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MFC/R2 call setup library

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

BUILD_DEPENDS=	${LOCALBASE}/include/dahdi/user.h:misc/dahdi

USE_GITHUB=	yes
GH_ACCOUNT=	moises-silva
GH_TAGNAME=	d6a5716

USES=		libtool localbase
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/r2proto.conf \
		${STAGEDIR}${PREFIX}/etc/r2proto.conf.sample
	${MV} ${STAGEDIR}${PREFIX}/etc/r2test.conf \
		${STAGEDIR}${PREFIX}/etc/r2test.conf.sample

.include <bsd.port.mk>
