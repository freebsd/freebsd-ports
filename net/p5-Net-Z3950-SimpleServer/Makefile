# New ports collection makefile for:	p5-Net-Z3950-SimpleServer
# Date created:				12 March 2002
# Whom:                			Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-Z3950-SimpleServer
PORTVERSION=	0.07
CATEGORIES=	net perl5
MASTER_SITES=	http://ftp.indexdata.dk/pub/simpleserver/
PKGNAMEPREFIX=	p5-

MAINTAINER=	demon@FreeBSD.org

LIB_DEPENDS=	yaz.1:${PORTSDIR}/net/yaz

PERL_CONFIGURE=	yes
CONFIGURE_ENV+=	LOCALBASE=${LOCALBASE}

MAN3=		Net::Z3950::GRS1.3 Net::Z3950::SimpleServer.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
