# New ports collection makefile for:	p5-Net
# Version required:			1.01
# Date created:				September 30th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id$
#

DISTNAME=	libnet-1.01
PKGNAME=	p5-Net-1.01
CATEGORIES+=	net
MASTER_SITES=	ftp://ftp.digital.com/pub/plan/perl/CPAN/modules/by-module/Net/ \
		ftp://ftp.cdrom.com/pub/perl/CPAN/modules/by-module/Net/ \
		ftp://ftp.cis.ufl.edu/pub/perl/CPAN/modules/by-module/Net/ \
		ftp://ftp.leo.org/pub/comp/programming/languages/perl/CPAN/modules/by-module/Net/ \
		ftp://ftp.demon.co.uk/pub/mirrors/perl/CPAN/modules/by-module/Net/ \
		ftp://ftp.lab.kdd.co.jp/lang/perl/CPAN/modules/by-module/Net/

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	perl5.003:${PORTSDIR}/lang/perl5 \
		${PREFIX}/lib/perl5/IO::Socket.pm:${PORTSDIR}/net/p5-IO

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

post-install:
.if !defined(NOMANCOMPRESS)
		@ for file in Net::Time Net::DummyInetd Net::NNTP Net::SNPP Net::POP3 Net::Cmd Net::SMTP Net::Domain Net::FTP Net::Netrc Net::Telnet; do \
			gzip -9nf ${PREFIX}/lib/perl5/man/man3/$$file.3; \
		done
.endif           

.include <bsd.port.mk>
