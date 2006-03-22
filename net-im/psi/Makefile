# New ports collection makefile for:	psi
# Date created:		Wed May  1 20:27:23 NZST 2002
# Whom:			jonc@chen.org.nz
#
# $FreeBSD$
#

PORTNAME=	psi
PORTVERSION=	0.10
CATEGORIES=	net-im
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	A Qt-based Jabber client

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake
LIB_DEPENDS=	qca.1:${PORTSDIR}/devel/qca
RUN_DEPENDS=	${X11BASE}/lib/plugins/crypto/libqca-tls.so:${PORTSDIR}/security/qca-tls

HAS_CONFIGURE=	yes
USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_QT_VER=	3

CONFIGURE_ENV=	QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++ \
		PTHREAD_CFLAGS=${PTHREAD_CFLAGS} \
		PTHREAD_LDFLAGS=${PTHREAD_LIBS} \
		KDEDIR=${LOCALBASE}
CONFIGURE_ARGS=	--prefix=${PREFIX} --qtdir=${X11BASE} \
		--with-qca-inc=${X11BASE}/include/plugins/qca \
		--with-qca-lib=${X11BASE}/lib \
		--disable-growl --disable-dnotify --disable-ghbnr
MAKE_ARGS+=	QTDIR=${X11BASE} \
		QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++

PORTDOCS=	README ChangeLog

post-install:
	${STRIP_CMD} ${PREFIX}/bin/psi
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
