# New ports collection makefile for:	p5-Mail-Tools
# Date created:				October 24th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Mail-Tools
PORTVERSION=	1.51
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Mail
PKGNAMEPREFIX=	p5-
DISTNAME=	MailTools-${PORTVERSION}

MAINTAINER=	kuriyama@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Net/SMTP.pm:${PORTSDIR}/net/p5-Net
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Mail::Address.3 \
		Mail::Cap.3 \
		Mail::Field.3 \
		Mail::Field::AddrList.3 \
		Mail::Filter.3 \
		Mail::Header.3 \
		Mail::Internet.3 \
		Mail::Mailer.3 \
		Mail::Send.3 \
		Mail::Util.3

.include <bsd.port.mk>
