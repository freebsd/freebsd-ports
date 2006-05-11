# ex:ts=8
# New ports collection makefile for:	xmlrpc-c
# Date created:			Mar 8, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xmlrpc-c
PORTVERSION=	0.9.10
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XML-RPC library for C and C++

LIB_DEPENDS=	wwwcore.1:${PORTSDIR}/www/libwww
RUN_DEPENDS=	${SITE_PERL}/Frontier/Client.pm:${PORTSDIR}/net/p5-Frontier-RPC

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

MAN1=	meerkat-app-list.1 xml-rpc-api2cpp.1 xmlrpc-c-config.1 \
	query-meerkat.1 xml-rpc-api2txt.1
MAN7=	xmlrpc-c.7

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
