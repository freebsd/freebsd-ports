# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	toxic
PORTVERSION=	0.4.0.140611
CATEGORIES=	net-im

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	A console client for Tox

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/lib/libtoxcore.a:${PORTSDIR}/net-im/tox
LIB_DEPENDS=	libvpx.so:${PORTSDIR}/multimedia/libvpx		\
		libopus.so:${PORTSDIR}/audio/opus		\
		libopenal.so.1:${PORTSDIR}/audio/openal-soft
RUN_DEPENDS=	${LOCALBASE}/lib/libtoxcore.a:${PORTSDIR}/net-im/tox

USE_GITHUB=	yes
GH_ACCOUNT=	tox
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	328e7f8

WRKSRC=		${WRKDIR}/Tox-${PORTNAME}-${GH_COMMIT}
SUB_FILES=	pkg-message

USES=		ncurses:port pkgconfig
USE_AUTOTOOLS=	autoconf aclocal

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 900033
USE_BINUTILS=	yes
LDFLAGS+=	-B${LOCALBASE}/bin
.endif

run-autotools:
	cd ${CONFIGURE_WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${AUTORECONF} -if

post-install:
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/misc/toxic.conf ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
