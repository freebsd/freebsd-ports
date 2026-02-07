PORTNAME=	Net-Z3950-SimpleServer
PORTVERSION=	1.20
PORTREVISION=	2
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Perl module for developing Z39.50 servers
WWW=		https://www.indexdata.dk/simpleserver/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libyaz.so:net/yaz

USES=		perl5 shebangfix
SHEBANG_FILES=	ztest.pl grs_test.pl logging-server.pl
USE_PERL5=	configure
CONFIGURE_ENV=	LOCALBASE=${LOCALBASE}

.include <bsd.port.mk>
