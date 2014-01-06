# $FreeBSD$

PORTNAME=	HTTP-Session-Store-DBI
PORTVERSION=	0.02
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to store session data in DBI for HTTP::Session

BUILD_DEPENDS=	\
	p5-Moose>0:${PORTSDIR}/devel/p5-Moose \
	p5-HTTP-Session>=0.26:${PORTSDIR}/www/p5-HTTP-Session \
	p5-DBI>0:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
