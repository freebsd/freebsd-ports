# New ports collection makefile for:	Qt port of Plastik
# Date Created:				30 Oct 2006
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	polymer
PORTVERSION=	0.3.1
PORTREVISION=	5
CATEGORIES=	x11-themes
MASTER_SITES=	http://static.int.pl/~mig21/dev/releases/polymer/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	danfe

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Qt port of Plastik KDE theme

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

USE_BZIP2=	yes
USE_AUTOTOOLS=	autoheader:262
USE_QT_VER=	3
USE_LDCONFIG=	yes

MAKE_ARGS+=	QTDIR=${QT_PREFIX} \
		QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++ \
		QMAKE=${LOCALBASE}/bin/qmake
CONFIGURE_ENV+=	THREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		THREAD_LIBS="${PTHREAD_LIBS}"

QTSTYLESDIR=	${PREFIX}/lib/plugins/styles

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
BROKEN=		Does not compile on amd64
.endif

.if ${MACHINE_CPU:Mmmx}
CONFIGURE_ARGS+=	--enable-mmx
.endif
.if ${MACHINE_CPU:Msse2}
CONFIGURE_ARGS+=	--enable-sse2
.endif

do-install:
	@${MKDIR} ${QTSTYLESDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/style/libpolymer.so.1.0.0 \
		${QTSTYLESDIR}/polymer.so
	${INSTALL_PROGRAM} ${WRKSRC}/config/polymer-config ${PREFIX}/bin

.include <bsd.port.post.mk>
