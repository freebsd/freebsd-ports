# $FreeBSD$

PORTNAME=	yices
DISTVERSION=	2.6.0
CATEGORIES=	math
MASTER_SITES=	http://yices.csl.sri.com/releases/${DISTVERSION}/
DISTNAME=	${PORTNAME}-${DISTVERSION}-src

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SMT solver

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	gperf:devel/gperf
LIB_DEPENDS=	libgmp.so:math/gmp

USES=		gmake localbase
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pic-gmp=${LOCALBASE}/lib/libgmp.so
USE_LDCONFIG=	yes

MAKE_ARGS=	YICES_MAKE_INCLUDE=configs/make.include.${CONFIGURE_TARGET}
CFLAGS+=	-fPIC

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/lib/*.a
	@cd ${STAGEDIR}${PREFIX}/lib && ${LN} -s libyices.so.2.6 libyices.so && ${LN} -s libyices.so.2.6 libyices.so.2

.include <bsd.port.mk>
