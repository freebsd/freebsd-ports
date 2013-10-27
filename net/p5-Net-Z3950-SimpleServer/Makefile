# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net-Z3950-SimpleServer
PORTVERSION=	1.16
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	demon@FreeBSD.org
COMMENT=	A Perl module for developing Z39.50 servers

LIB_DEPENDS=	yaz:${PORTSDIR}/net/yaz

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ENV=	LOCALBASE=${LOCALBASE}

MAN3=		Net::Z3950::GRS1.3 Net::Z3950::SimpleServer.3

NO_STAGE=	yes
.include <bsd.port.mk>
