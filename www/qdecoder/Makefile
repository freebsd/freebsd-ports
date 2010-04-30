# New ports collection makefile for:    qDecoder library
# Date created:         Sep 10 1999
# Whom:                 CHOI Junho <cjh@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	qdecoder
PORTVERSION=	10.1.4
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.qdecoder.org/pub/qDecoder/
DISTNAME=	qDecoder-${PORTVERSION}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	C/C++ language library including CGI supports

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
MAKE_ARGS=	exec_prefix="${PREFIX}"

OPTIONS=	Q_DEBUG "enable debuging output" off \
		Q_CGI "enable CGI APIs" on \
		Q_SOCKET "enable socket APIs" on \
		Q_IPC "enable IPC APIs" on \
		Q_DATASTRUCTURE "enable data-structure APIs" on \
		Q_MYSQL "enable MySQL database supports" off \
		Q_LFS "enable large-file supports" off \
		Q_SENDFILE "use sendfile() if possible" off

PLIST_FILES=	include/qDecoder.h \
		lib/libqDecoder.a \
		lib/libqDecoder.so \
		lib/libqDecoder.so.8

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif
.if !defined(NOPORTEXAMPLES)
PORTEXAMPLES=	*
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_Q_DEBUG)
CONFIGURE_ARGS+="--enable-debug"
.endif

.if defined(WITH_Q_LFS)
CONFIGURE_ARGS+="--enable-lfs"
.endif

.if defined(WITH_Q_SENDFILE)
CONFIGURE_ARGS+="--enable-sendfile"
.endif

.if defined(WITH_Q_MYSQL)
CONFIGURE_ARGS+="--enable-mysql=${LOCALBASE}/include/mysql"
USE_MYSQL=yes
.endif

.if defined(WITHOUT_Q_CGI)
CONFIGURE_ARGS+="--disable-cgi"
.endif

.if defined(WITHOUT_Q_SOCKET)
CONFIGURE_ARGS+="--disable-socket"
.endif

.if defined(WITHOUT_Q_IPC)
CONFIGURE_ARGS+="--disable-ipc"
.endif

.if defined(WITHOUT_Q_DATASTRUCTURE)
CONFIGURE_ARGS+="--disable-datastructure"
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "AUTHORS CHANGES COPYING INSTALL qDecoder.jpg" ${DOCSDIR})
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} "html" ${DOCSDIR})
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} "Makefile *.c *.conf *.html* qDecoder-upload" ${EXAMPLESDIR})
.endif

.include <bsd.port.post.mk>
