# Created by: Yi-Jheng, Lin <yzlin@cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	BBS-Client
PORTVERSION=	0.03
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:CORNELIUS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A Client Module For BBS Systems

BUILD_DEPENDS=	p5-Net-Telnet>=0:${PORTSDIR}/net/p5-Net-Telnet
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
