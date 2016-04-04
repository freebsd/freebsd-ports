# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	libproj4
DISTVERSION=	3_20081120
CATEGORIES=	math geography
MASTER_SITES=	http://home.comcast.net/~gevenden56/proj/
DISTFILES=	${PORTNAME}.${DISTVERSION}${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	C language procedures related to cartographic processes

LIB_DEPENDS=	libgsl.so:math/gsl

USES=		gmake tar:bzip2
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
ALL_TARGET=	libproj4 lproj
MAKE_JOBS_UNSAFE=yes
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDOCS}
DISTFILES+=	manual.pdf
EXTRACT_ONLY=	${PORTNAME}.${DISTVERSION}${EXTRACT_SUFX}
.endif

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1000034
LIB_DEPENDS+=	libmissing.so:math/libmissing
LDFLAGS+=	-lmissing
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${_DISTDIR}/manual.pdf ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.post.mk>
