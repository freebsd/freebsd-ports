# New ports collection makefile for:	sblim-wbemcli
# Date created:		20 Dec 2008
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sblim-wbemcli
PORTVERSION=	1.6.1
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/sblim/${PORTNAME}/${PORTVERSION}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	CLI for Web Based Enterprise Management by SBLIM

BUILD_DEPENDS=	libwww-config:${PORTSDIR}/www/libwww
LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl

USE_BZIP2=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ENV=	CPPFLAGS="-I${PREFIX}/include" LDFLAGS="-L${PREFIX}/lib"
MAKE_ARGS=	RM="${RM} -f"
MAN1=		wbemcli.1

.include <bsd.port.mk>
