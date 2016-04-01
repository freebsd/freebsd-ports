# Created by: will
# $FreeBSD$

PORTNAME=	Mail-Box
PORTVERSION=	2.109
PORTREVISION=	2
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MARKOV
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Perl module implementing a modern mail folder management

COMMON_DEPENDS=	\
	p5-MIME-Tools>=0:mail/p5-MIME-Tools \
	p5-MIME-Types>=0:mail/p5-MIME-Types \
	p5-Mail-Tools>=0:mail/p5-Mail-Tools \
	p5-Devel-GlobalDestruction>=0.09:devel/p5-Devel-GlobalDestruction \
	p5-Digest-HMAC>=0:security/p5-Digest-HMAC \
	p5-File-Remove>=0.20:devel/p5-File-Remove \
	p5-HTML-Format>=2.01:textproc/p5-HTML-Format \
	p5-HTML-Tree>=3.13:www/p5-HTML-Tree \
	p5-IO-stringy>=0:devel/p5-IO-stringy \
	p5-Mail-IMAPClient>=2.2.8:mail/p5-Mail-IMAPClient \
	p5-Mail-Transport-Dbx>=0.04:mail/p5-Mail-Transport-Dbx \
	p5-Object-Realize-Later>=0.14:devel/p5-Object-Realize-Later \
	p5-TimeDate>=0:devel/p5-TimeDate \
	p5-URI>=1.23:net/p5-URI \
	p5-User-Identity>=0.90:devel/p5-User-Identity
BUILD_DEPENDS=	${COMMON_DEPENDS}
RUN_DEPENDS=	${COMMON_DEPENDS}
TEST_DEPENDS=	p5-Test-Pod>=1.00:devel/p5-Test-Pod

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ARGS=	</dev/null
CONFIGURE_ENV+=	MAILBOX_INSTALL_OPTIONALS=n


.include <bsd.port.mk>
