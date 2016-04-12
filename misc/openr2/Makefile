# Created by: Max Khon <fjoe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openr2
PORTVERSION=	1.3.3
PORTREVISION=	0
CATEGORIES=	misc
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	MFC/R2 call setup library

BUILD_DEPENDS=	${LOCALBASE}/include/dahdi/user.h:misc/dahdi

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
INSTALL_TARGET=	install-strip
USES=		libtool
USE_LDCONFIG=	yes

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/r2proto.conf \
		${STAGEDIR}${PREFIX}/etc/r2proto.conf.sample
	${MV} ${STAGEDIR}${PREFIX}/etc/r2test.conf \
		${STAGEDIR}${PREFIX}/etc/r2test.conf.sample

.include <bsd.port.mk>
