# New ports collection makefile for:	shmux
# Date created:				2 September 2004
# Whom:					jamundsen
#
# $FreeBSD$
#

PORTNAME=	shmux
DISTVERSION=	1.0b4
CATEGORIES=	net
MASTER_SITES=	http://web.taranis.org/shmux/dist/
EXTRACT_SUFX=	.tgz

MAINTAINER=	online@jamundsen.dyndns.org
COMMENT=	Utility to run commands on multiple hosts using shell commands

OPTIONS=	FPING "Use fping utility" on	\
		PCRE "Use perl regular expressions library" off

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${PREFIX}/share/examples

ALL_TARGET=	${PORTNAME}

MAN1=		shmux.1
MANCOMPRESSED=	no

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_FPING)
RUN_DEPENDS+=	fping:${PORTSDIR}/net/fping
.endif

.if defined(WITH_PCRE)
LIB_DEPENDS+=	pcre.0:${PORTSDIR}/devel/pcre
CONFIGURE_ARGS+=	--with-pcre=${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=	--with-pcre=no
.endif

.include <bsd.port.post.mk>
