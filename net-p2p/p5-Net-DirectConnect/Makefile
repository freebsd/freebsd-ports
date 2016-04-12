# Created by: Oleg Alexeenkov <proler@gmail.com>
# $FreeBSD$

PORTNAME=	Net-DirectConnect
PORTVERSION=	0.14
PORTREVISION=	1
CATEGORIES=	net-p2p net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	proler@gmail.com
COMMENT=	Perl Direct Connect lib and client

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-DBD-SQLite>=0:databases/p5-DBD-SQLite \
		p5-DBI>=0:databases/p5-DBI \
		p5-IO-Socket-INET6>=0:net/p5-IO-Socket-INET6 \
		p5-IO-Socket-SSL>=0:security/p5-IO-Socket-SSL \
		p5-Crypt-RHash>=0:security/p5-Crypt-RHash \
		p5-Socket6>=0:net/p5-Socket6 \
		p5-lib-abs>=0:devel/p5-lib-abs \
		p5-MIME-Base32>=0:converters/p5-MIME-Base32 \
		p5-Sys-Sendfile-FreeBSD>=0:devel/p5-Sys-Sendfile-FreeBSD
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
