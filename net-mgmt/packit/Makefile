# New ports collection makefile for:  		packit
# Date created:        				02.06.2003
# Whom:               				Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	packit
PORTVERSION=	0.6.0
CATEGORIES=	net
MASTER_SITES=	http://packit.sourceforge.net/
DISTNAME=	${PORTNAME}-latest
EXTRACT_SUFX=	.tgz

MAINTAINER=	ponomarew@oberon.net
COMMENT=	Packit is a network auditing tool

BUILD_DEPENDS=	${LOCALBASE}/lib/libnet.a:${PORTSDIR}/net/libnet-devel

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet-config

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN8=		packit.8

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib" \

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} ""#######################################################
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You need ${PORTSDIR}/net/libnet-devel to build this port
	@${ECHO_MSG} ""
	@${ECHO_MSG} ""#######################################################
	@${ECHO_MSG} ""

.include <bsd.port.mk>
