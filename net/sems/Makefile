# Created by: Nathan Whitehon <nwhitehorn@freebsd.org>
# $FreeBSD$

PORTNAME=	sems
DISTVERSION=	${SEMS_VERSION}.g20190822
CATEGORIES=	net

MAINTAINER=	nwhitehorn@FreeBSD.org
COMMENT=	SIP Express Media Server

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/doc/COPYING

LIB_DEPENDS=	libopus.so:audio/opus \
		libcodec2.so:audio/codec2 \
		libevent.so:devel/libevent \
		librtmp.so:multimedia/librtmp \
		libilbc.so:net/ilbc \
		libgsm.so:audio/gsm \
		libsamplerate.so:audio/libsamplerate \
		libspeex.so:audio/speex \
		libspandsp.so:comms/spandsp

USES=		cmake compiler:c++11-lang python:2.7,run shebangfix
SHEBANG_GLOB=	sems-*

USE_GITHUB=	yes
GH_ACCOUNT=	sems-server
GH_TAGNAME=	7400051

CFLAGS+=	-Wno-reorder
CMAKE_ARGS=	-DSEMS_CFG_PREFIX=${PREFIX} -DSEMS_AUDIO_PREFIX=${PREFIX}/lib \
		-DSEMS_EXEC_PREFIX=${PREFIX} -DSEMS_DOC_PREFIX=${PREFIX}/share/doc
CMAKE_ON=	SEMS_USE_SPANDSP SEMS_USE_LIBSAMPLERATE SEMS_USE_OPUS

USE_RC_SUBR=	sems

USERS=		sems
GROUPS=		sems

SEMS_VERSION=	1.7.0
PLIST_SUB=	SEMS_VERSION=${SEMS_VERSION}

post-install:
	cd ${STAGEDIR}${ETCDIR} && ${FIND} . \
	    -type f -exec ${MV} {} {}.sample \;

.include <bsd.port.mk>
