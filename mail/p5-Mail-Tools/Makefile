# New ports collection makefile for:	p5-Mail-Tools
# Version required:			1.12
# Date created:				October 24th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	MailTools-1.12
PKGNAME=	p5-Mail-Tools-1.12
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Mail

MAINTAINER=	jfitz@FreeBSD.org

BUILD_DEPENDS=	${PREFIX}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Net/SMTP.pm:${PORTSDIR}/net/p5-Net \
		${PREFIX}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Net/Domain.pm:${PORTSDIR}/net/p5-Net
RUN_DEPENDS=	${PREFIX}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Net/SMTP.pm:${PORTSDIR}/net/p5-Net \
		${PREFIX}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Net/Domain.pm:${PORTSDIR}/net/p5-Net

USE_PERL5=	YES

MAN3=		Mail::Address.3 Mail::Cap.3 Mail::Field.3 Mail::Header.3 \
		Mail::Internet.3 Mail::Alias.3 Mail::Mailer.3 Mail::Send.3 \
		Mail::Util.3 Mail::Field::AddrList.3 Mail::Filter.3

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
