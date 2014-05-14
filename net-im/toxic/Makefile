# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	toxic
PORTVERSION=	0.3.3.140508
CATEGORIES=	net-im

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	A console client for Tox

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/lib/libtoxcore.a:${PORTSDIR}/net-im/tox
RUN_DEPENDS=	${LOCALBASE}/lib/libtoxcore.a:${PORTSDIR}/net-im/tox

USE_GITHUB=	yes
GH_ACCOUNT=	tox
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	af09961

WRKSRC=		${WRKDIR}/Tox-${PORTNAME}-${GH_COMMIT}
SUB_FILES=	pkg-message

USES=		ncurses:port pkgconfig
USE_AUTOTOOLS=	autoconf aclocal

run-autotools:
	cd ${CONFIGURE_WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${AUTORECONF} -if

post-install:
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/misc/toxic.conf ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
