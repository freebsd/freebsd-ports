# New ports collection makefile for:	Nmap-Scanner
# Date created:	   04 July 2003
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Nmap-Scanner
PORTVERSION=	0.7a
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/M/MA/MAXSCHUBE
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Perform and manipulate nmap scans using perl

BUILD_DEPENDS=	${SITE_PERL}/XML/SAX.pm:${PORTSDIR}/textproc/p5-XML-SAX
RUN_DEPENDS=	${BUILD_DEPENDS} \
		nmap:${PORTSDIR}/security/nmap

WRKSRC=		${WRKDIR}/${PORTNAME}-0.7

PERL_CONFIGURE=	yes

MAN3=		Nmap::Scanner.3 Nmap::Scanner::Address.3 \
		Nmap::Scanner::Backend::Processor.3 \
		Nmap::Scanner::Backend::Results.3 Nmap::Scanner::ExtraPorts.3 \
		Nmap::Scanner::Host.3 Nmap::Scanner::Hostname.3 \
		Nmap::Scanner::Hosts.3 Nmap::Scanner::NmapRun.3 \
		Nmap::Scanner::OS.3 Nmap::Scanner::OS::Class.3 \
		Nmap::Scanner::OS::IPIdSequence.3 Nmap::Scanner::OS::Match.3 \
		Nmap::Scanner::OS::PortUsed.3 Nmap::Scanner::OS::TCPSequence.3 \
		Nmap::Scanner::OS::TCPTSSequence.3 Nmap::Scanner::OS::Uptime.3 \
		Nmap::Scanner::Port.3 Nmap::Scanner::RunStats.3 \
		Nmap::Scanner::ScanInfo.3 Nmap::Scanner::Scanner.3 \
		Nmap::Scanner::Service.3

post-configure:
	@${PERL} -pi -e 's/^(POD2MAN_EXE.*)$$/\1 --lax/;' ${WRKSRC}/Makefile

.include <bsd.port.mk>
