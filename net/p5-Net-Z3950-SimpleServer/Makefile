# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net-Z3950-SimpleServer
PORTVERSION=	1.19
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	demon@FreeBSD.org
COMMENT=	A Perl module for developing Z39.50 servers

LIB_DEPENDS=	libyaz.so:${PORTSDIR}/net/yaz

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ENV=	LOCALBASE=${LOCALBASE}

.include <bsd.port.mk>
