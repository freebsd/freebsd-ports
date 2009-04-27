# New ports collection makefile for:	Mail-Box
# Date created:				Wed Jan  3 12:54:59 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	Mail-Box
PORTVERSION=	2.089
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Perl module implementing a modern mail folder management

BUILD_DEPENDS=	\
	${SITE_PERL}/MIME/Entity.pm:${PORTSDIR}/mail/p5-MIME-Tools \
	${SITE_PERL}/MIME/Types.pm:${PORTSDIR}/mail/p5-MIME-Types \
	${SITE_PERL}/Mail/Internet.pm:${PORTSDIR}/mail/p5-Mail-Tools \
	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple \
	p5-Digest-HMAC>=0:${PORTSDIR}/security/p5-Digest-HMAC \
	p5-Encode>=2.26:${PORTSDIR}/converters/p5-Encode \
	p5-File-Remove>=0.20:${PORTSDIR}/devel/p5-File-Remove \
	p5-HTML-Format>=2.01:${PORTSDIR}/textproc/p5-HTML-Format \
	p5-HTML-Tree>=3.13:${PORTSDIR}/www/p5-HTML-Tree \
	p5-IO-stringy>=0:${PORTSDIR}/devel/p5-IO-stringy \
	p5-MIME-Base64>=0:${PORTSDIR}/converters/p5-MIME-Base64 \
	p5-Mail-IMAPClient>=2.2.8:${PORTSDIR}/mail/p5-Mail-IMAPClient \
	p5-Mail-Transport-Dbx>=0.04:${PORTSDIR}/mail/p5-Mail-Transport-Dbx \
	p5-Object-Realize-Later>=0.14:${PORTSDIR}/devel/p5-Object-Realize-Later \
	p5-Scalar-List-Utils>=1.13:${PORTSDIR}/lang/p5-Scalar-List-Utils \
	p5-Time-HiRes>=1.51:${PORTSDIR}/devel/p5-Time-HiRes \
	p5-TimeDate>=0:${PORTSDIR}/devel/p5-TimeDate \
	p5-URI>=1.23:${PORTSDIR}/net/p5-URI \
	p5-User-Identity>=0.90:${PORTSDIR}/devel/p5-User-Identity \
	p5-Test-Harness>=3.00:${PORTSDIR}/devel/p5-Test-Harness
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+
CONFIGURE_ARGS=	</dev/null
CONFIGURE_ENV+=	MAILBOX_INSTALL_OPTIONALS=n

.include "Makefile.man"
.include <bsd.port.mk>
