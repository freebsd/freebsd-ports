# New ports collection makefile for:	p5-BBS-Client
# Date created:		2008-05-30
# Whom:			Yi-Jheng, Lin <yzlin@cs.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	BBS-Client
PORTVERSION=	0.03
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/C/CO/CORNELIUS
PKGNAMEPREFIX=	p5-

MAINTAINER=	yzlin@FreeBSD.org
COMMENT=	A Client Module For BBS Systems

BUILD_DEPENDS=	${SITE_PERL}/Net/Telnet.pm:${PORTSDIR}/net/p5-Net-Telnet
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		BBS::Client.3

.include <bsd.port.mk>
