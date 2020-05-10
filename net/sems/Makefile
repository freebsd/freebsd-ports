# Created by: Nathan Whitehon <nwhitehorn@freebsd.org>
# $FreeBSD$

PORTNAME=	sems
DISTVERSION=	${SEMS_VERSION}.g20200510
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

USES=		cmake compiler:c++11-lang python:3.4+,run shebangfix ssl
SHEBANG_GLOB=	sems-*

PY2TO3_CMD=	${LOCALBASE}/bin/2to3-${PYTHON_VER}
PY2TO3_ARGS=	--fix=all --no-diffs --nobackups --verbose --write

USE_GITHUB=	yes
GH_ACCOUNT=	sems-server
GH_TAGNAME=	f89581a

CFLAGS+=	-Wno-reorder
CMAKE_ARGS=	-DSEMS_CFG_PREFIX=${PREFIX} -DSEMS_AUDIO_PREFIX=${PREFIX}/lib \
		-DSEMS_EXEC_PREFIX=${PREFIX} -DSEMS_DOC_PREFIX=${PREFIX}/share/doc
CMAKE_ON=	SEMS_USE_SPANDSP SEMS_USE_LIBSAMPLERATE SEMS_USE_OPUS \
		SEMS_USE_OPENSSL

USE_RC_SUBR=	sems

USERS=		sems
GROUPS=		sems

SEMS_VERSION=	1.7.0
PLIST_SUB=	SEMS_VERSION=${SEMS_VERSION}

FIXUP_2TO3=	sbin/sems-get-callproperties sbin/sems-list-active-calls \
		sbin/sems-list-calls sbin/sems-list-finished-calls \
		sbin/sems-sbc-get-activeprofile \
		sbin/sems-sbc-get-regex-map-names sbin/sems-sbc-list-profiles \
		sbin/sems-sbc-load-callcontrol-modules \
		sbin/sems-sbc-load-profile sbin/sems-sbc-reload-profile \
		sbin/sems-sbc-reload-profiles sbin/sems-sbc-set-activeprofile \
		sbin/sems-sbc-set-regex-map sbin/sems-sbc-teardown-call

post-install:
.	for p in ${FIXUP_2TO3}
	${PY2TO3_CMD} ${PY2TO3_ARGS} ${STAGEDIR}${PREFIX}/${p}
.	endfor

	cd ${STAGEDIR}${ETCDIR} && ${FIND} . \
	    -type f -exec ${MV} {} {}.sample \;

.include <bsd.port.mk>
