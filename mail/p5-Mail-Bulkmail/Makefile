# New ports collection makefile for:	Mail-Bulkmail
# Date created:				Wed Jan  3 13:26:45 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	Mail-Bulkmail
PORTVERSION=	3.12
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Mail
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Perl module for mailing lists

PERL_CONFIGURE=	yes

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
