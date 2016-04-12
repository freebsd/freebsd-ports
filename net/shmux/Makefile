# Created by: jamundsen
# $FreeBSD$

PORTNAME=	shmux
DISTVERSION=	1.0.2
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://web.taranis.org/shmux/dist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility to run commands on multiple hosts using shell commands

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		ncurses tar:tgz
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${PREFIX}/share/examples

ALL_TARGET=	${PORTNAME}

OPTIONS_DEFINE=		FPING PCRE
OPTIONS_DEFAULT=	FPING
FPING_DESC=	Use fping utility

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFPING}
RUN_DEPENDS+=	fping:net/fping
.endif

.if ${PORT_OPTIONS:MPCRE}
LIB_DEPENDS+=	libpcre.so:devel/pcre
CONFIGURE_ARGS+=	--with-pcre=${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=	--with-pcre=no
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
