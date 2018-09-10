# Created by: will
# $FreeBSD$

PORTNAME=	Mail-Bulkmail
PORTVERSION=	3.12
PORTREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module for mailing lists

USES=		perl5
USE_PERL5=	configure patch

post-patch:
	${PERL} -pi -e '$$_="" if /^use 5/;' \
		-e '$$_="" if /(use|no) warnings/;' \
		${WRKSRC}/Bulkmail.pm ${WRKSRC}/Bulkmail/Object.pm \
		${WRKSRC}/Bulkmail/Dynamic.pm \
		${WRKSRC}/Bulkmail/Server.pm \
		${WRKSRC}/Bulkmail/DummyServer.pm

.include <bsd.port.mk>
