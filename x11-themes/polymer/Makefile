# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	polymer
PORTVERSION=	0.3.1
PORTREVISION=	10
CATEGORIES=	x11-themes
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	danfe

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Pure Qt3 port of Plastik KDE theme

LICENSE=	GPLv2

DEPRECATED=	Qt 3.x is unsupported upstream; its port scheduled for removal

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

USE_BZIP2=	yes
USE_AUTOTOOLS=	autoheader
USE_GMAKE=	yes	# parallel builds (-jX) are broken with BSD make(1)
USE_QT_VER=	3

MAKE_ARGS+=	QTDIR=${QT_PREFIX} \
		QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++ \
		QMAKE=${LOCALBASE}/bin/qmake
CONFIGURE_ENV+=	THREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		THREAD_LIBS="${PTHREAD_LIBS}"

QTSTYLESDIR=	${PREFIX}/lib/plugins/styles

MAN1=		polymer-config.1
PORTDOCS=	AUTHORS ChangeLog README TODO

.include <bsd.port.pre.mk>

.if ${ARCH} == i386
.if ${MACHINE_CPU:Mmmx}
CONFIGURE_ARGS+=	--enable-mmx
.endif
.if ${MACHINE_CPU:Msse2}
CONFIGURE_ARGS+=	--enable-sse2
.endif
.endif

do-install:
	@${MKDIR} ${QTSTYLESDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/style/libpolymer.so.1.0.0 \
		${QTSTYLESDIR}/polymer.so
	${INSTALL_PROGRAM} ${WRKSRC}/config/polymer-config ${PREFIX}/bin
	${INSTALL_MAN} ${FILESDIR}/polymer-config.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
