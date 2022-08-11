PORTNAME=	shmux
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.3
CATEGORIES=	net

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility to run commands on multiple hosts using shell commands

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		localbase ncurses
USE_GITHUB=	yes

GNU_CONFIGURE=	yes
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
