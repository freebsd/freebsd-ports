# Created by: Shell Hung <shell@shellhung.org>
# $FreeBSD$

PORTNAME=	Date-Handler
PORTVERSION=	1.2
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module for calculating time differences

USES=		perl5
USE_PERL5=	configure patch

MAN3=		Date::Handler.3 Date::Handler::Delta.3 \
		Date::Handler::Range.3 Date::Handler::Test.3

post-patch:
	@${PERL} -pi -e 's/[a-z][a-z]_[A-Z][A-Z]/$$&.ISO8859-15/g' \
		${WRKSRC}/Handler.* ${WRKSRC}/README*

.include <bsd.port.mk>
