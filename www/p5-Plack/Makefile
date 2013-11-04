# $FreeBSD$

PORTNAME=	Plack
PORTVERSION=	1.0029
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MIYAGAWA
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension of PSGI reference implementation and utilities

RUN_DEPENDS=	\
	p5-Apache-LogFormat-Compiler>=0.12:${PORTSDIR}/www/p5-Apache-LogFormat-Compiler \
	p5-Devel-StackTrace>=1.23:${PORTSDIR}/devel/p5-Devel-StackTrace \
	p5-Devel-StackTrace-AsHTML>=0.11:${PORTSDIR}/devel/p5-Devel-StackTrace-AsHTML \
	p5-File-ShareDir>=1.00:${PORTSDIR}/devel/p5-File-ShareDir \
	p5-Filesys-Notify-Simple>0:${PORTSDIR}/devel/p5-Filesys-Notify-Simple \
	p5-HTTP-Body>=1.06:${PORTSDIR}/www/p5-HTTP-Body \
	p5-HTTP-Tiny>=0.034:${PORTSDIR}/www/p5-HTTP-Tiny \
	p5-Hash-MultiValue>=0.05:${PORTSDIR}/devel/p5-Hash-MultiValue \
	p5-Path-Class>0:${PORTSDIR}/devel/p5-Path-Class \
	p5-Stream-Buffered>=0.02:${PORTSDIR}/devel/p5-Stream-Buffered \
	p5-Try-Tiny>0:${PORTSDIR}/lang/p5-Try-Tiny \
	p5-URI>=1.59:${PORTSDIR}/net/p5-URI
BUILD_DEPENDS:=	${RUN_DEPENDS} \
	p5-File-ShareDir-Install>=0.03:${PORTSDIR}/devel/p5-File-ShareDir-Install
TEST_DEPENDS=  \
	p5-Authen-Simple-Passwd>0:${PORTSDIR}/security/p5-Authen-Simple-Passwd \
	p5-CGI-Compile>0:${PORTSDIR}/www/p5-CGI-Compile \
	p5-CGI-Emulate-PSGI>0:${PORTSDIR}/www/p5-CGI-Emulate-PSGI \
	p5-FCGI>0:${PORTSDIR}/www/p5-FCGI \
	p5-FCGI-ProcManager>0:${PORTSDIR}/www/p5-FCGI-ProcManager \
	p5-HTTP-Request-AsCGI>0:${PORTSDIR}/www/p5-HTTP-Request-AsCGI \
	p5-HTTP-Server-Simple-PSGI>0:${PORTSDIR}/www/p5-HTTP-Server-Simple-PSGI \
	p5-IO-Handle-Util>0:${PORTSDIR}/devel/p5-IO-Handle-Util \
	p5-LWP-Protocol-http10>0:${PORTSDIR}/www/p5-LWP-Protocol-http10 \
	p5-Log-Dispatch-Array>0:${PORTSDIR}/devel/p5-Log-Dispatch-Array \
	p5-Log-Log4perl>0:${PORTSDIR}/devel/p5-Log-Log4perl \
	p5-MIME-Types>0:${PORTSDIR}/mail/p5-MIME-Types \
	p5-Module-Refresh>0:${PORTSDIR}/devel/p5-Module-Refresh \
	p5-Stream-Buffered>=0.02:${PORTSDIR}/devel/p5-Stream-Buffered \
	p5-Test-Requires>0:${PORTSDIR}/devel/p5-Test-Requires \
	p5-Test-TCP>=2.00:${PORTSDIR}/devel/p5-Test-TCP

USES=	perl5
USE_PERL5=	configure

.include <bsd.port.mk>
