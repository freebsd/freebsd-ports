# New ports collection makefile for:	p5-Net
# Version required:                     1.0605
# Date created:				September 30th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $Id: Makefile,v 1.17 1998/04/29 09:41:39 vanilla Exp $
#

DISTNAME=       libnet-1.0605
PKGNAME=        p5-Net-1.0605
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net

MAINTAINER=	jfitz@FreeBSD.ORG

USE_PERL5=	YES

MANPREFIX=	${PREFIX}/lib/perl5/5.00501
MAN3=		Net::Time.3 Net::DummyInetd.3 Net::NNTP.3 Net::SNPP.3 \
		Net::POP3.3 Net::Cmd.3 Net::SMTP.3 Net::Domain.3 \
		Net::FTP.3 Net::Netrc.3 Net::PH.3 FAQ.3

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
