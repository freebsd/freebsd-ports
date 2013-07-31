# Created by: will
# $FreeBSD$

PORTNAME=	Mail-Bulkmail
PORTVERSION=	3.12
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Perl module for mailing lists

USES=		perl5
USE_PERL5=	configure patch

MAN3=		Mail::Bulkmail.3 Mail::Bulkmail::Dynamic.3 \
		Mail::Bulkmail::Server.3 Mail::Bulkmail::Object.3 \
		Mail::Bulkmail::DummyServer.3

post-patch:
	${PERL} -pi -e '$$_="" if /^use 5/;' \
		-e '$$_="" if /(use|no) warnings/;' \
		${WRKSRC}/Bulkmail.pm ${WRKSRC}/Bulkmail/Object.pm \
		${WRKSRC}/Bulkmail/Dynamic.pm \
		${WRKSRC}/Bulkmail/Server.pm \
		${WRKSRC}/Bulkmail/DummyServer.pm

.include <bsd.port.mk>
