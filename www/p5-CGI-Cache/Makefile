# Created by: will
# $FreeBSD$

PORTNAME=	CGI-Cache
PORTVERSION=	1.4214
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension to cache output of time-intensive CGI scripts

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-URI>=0:net/p5-URI \
		${RUN_DEPENDS}
RUN_DEPENDS=	p5-Cache>=0:devel/p5-Cache \
		p5-Cache-Cache>=0:devel/p5-Cache-Cache \
		p5-Tie-Restore>=0:devel/p5-Tie-Restore
TEST_DEPENDS=	p5-File-Slurper>=0:devel/p5-File-Slurper

PORTSCOUT=	skipv:1.4213

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
