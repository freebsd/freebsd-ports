# New ports collection makefile for:	p5-Net
# Version required:			1.01
# Date created:				September 30th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.2 1996/10/24 09:59:22 jfitz Exp $
#

DISTNAME=	libnet-1.01
PKGNAME=	p5-Net-1.01
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	perl5.003:${PORTSDIR}/lang/perl5 \
		${PREFIX}/lib/perl5/IO::Socket.pm:${PORTSDIR}/net/p5-IO
RUN_DEPENDS=	perl5.003:${PORTSDIR}/lang/perl5

MAN3=		Net::Time.3 Net::DummyInetd.3 Net::NNTP.3 Net::SNPP.3 \
		Net::POP3.3 Net::Cmd.3 Net::SMTP.3 Net::Domain.3 \
		Net::FTP.3 Net::Netrc.3 Net::Telnet.3
MANPREFIX=	${PREFIX}/lib/perl5

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
