# New ports collection makefile for:	p5-Net
# Version required:                     1.*
# Date created:				September 30th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=       libnet-1.0606
PKGNAME=        p5-Net-1.0606
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net

MAINTAINER=	jfitz@FreeBSD.org

USE_PERL5=	YES

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=           \
		Net::Cmd.3 \
		Net::Domain.3 \
		Net::DummyInetd.3 \
		Net::FTP.3 \
		Net::NNTP.3 \
		Net::Netrc.3 \
		Net::PH.3 \
		Net::POP3.3 \
		Net::SMTP.3 \
		Net::SNPP.3 \
		Net::Time.3

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
