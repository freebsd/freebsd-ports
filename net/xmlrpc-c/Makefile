# ex:ts=8
# New ports collection makefile for:	xmlrpc-c
# Date created:			Mar 8, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xmlrpc-c
PORTVERSION=	0.9.8
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ijliao@FreeBSD.org

LIB_DEPENDS=	wwwcore.1:${PORTSDIR}/www/libwww
RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Frontier/Client.pm:${PORTSDIR}/net/p5-Frontier-RPC

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

USE_GMAKE=	yes

INSTALLS_SHLIB=	yes

post-install:
	@${RM} -f ${PREFIX}/lib/*.la

.include <bsd.port.mk>
