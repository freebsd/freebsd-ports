PORTNAME=	shmux
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.3
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility to run commands on multiple hosts using shell commands
WWW=		https://github.com/shmux/shmux

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		localbase ncurses
USE_GITHUB=	yes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--datadir=${PREFIX}/share/examples

ALL_TARGET=	${PORTNAME}

OPTIONS_DEFINE=		FPING PCRE
OPTIONS_DEFAULT=	FPING
FPING_DESC=	Use fping utility

FPING_RUN_DEPENDS=	fping:net/fping
PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre
PCRE_CONFIGURE_WITH=	pcre=${LOCALBASE}/lib

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
