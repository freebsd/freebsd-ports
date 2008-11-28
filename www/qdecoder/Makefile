# New ports collection makefile for:    qDecoder library
# Date created:         Sep 10 1999
# Whom:                 CHOI Junho <cjh@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	qdecoder
PORTVERSION=	9.0.1
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.qdecoder.org/pub/qDecoder/
DISTNAME=	qDecoder-${PORTVERSION}

MAINTAINER=	cjh@FreeBSD.org
COMMENT=	C/C++ language library including CGI supports

CONFLICTS=	qDecoder-[5-7]*

HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes

OPTIONS=	Q_DEBUG "Debug printout" off
OPTIONS+=	Q_64BIT "64bit support" off
OPTIONS+=	Q_SENDFILE "Use sendfile()" off
OPTIONS+=	Q_MYSQL "Use MySQL" off
OPTIONS+=	Q_CGISUPPORT "CGI API support" on
OPTIONS+=	Q_SOCKET "Socket API support" on
OPTIONS+=	Q_IPC "IPC API support" on
OPTIONS+=	Q_DATASTRUCTURE "Datastructure API support" on

.include <bsd.port.pre.mk>

.if defined(WITH_Q_DEBUG)
CONFIGURE_ARGS+="--enable-debug"
.endif

.if defined(WITH_Q_64BIT)
CONFIGURE_ARGS+="--enable-64bit"
.endif

.if defined(WITH_Q_SENDFILE)
CONFIGURE_ARGS+="--enable-sendfile"
.endif

.if defined(WITH_Q_MYSQL)
CONFIGURE_ARGS+="--enable-mysql=${LOCALBASE}/include/mysql"
USE_MYSQL=yes
.endif

.if defined(WITHOUT_Q_CGISUPPORT)
CONFIGURE_ARGS+="--disable-cgisupport"
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
