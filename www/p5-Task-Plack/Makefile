# New ports collection makefile for:	Task::Plack
# Date created:		17 Apr 2010
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Task-Plack
PORTVERSION=	0.24
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl module bundle for Plack

PERL_CONFIGURE=	yes

MAN3=	Task::Plack.3

OPTIONS=FASTCGI	"FastCGI daemon and dispatcher" off \
	STACKTRACE "Stacktrace with lexical variables" off \
	HANDLEIO "Utility to create IO::Handle-ish objects" off \
	CORE "Core and Essential Tools" on \
	SERVER "Recommended PSGI Servers and Plack handlers" off \
	EXTRASRV "Extra PSGI servers and Plack handlers" off \
	MIDDLE "Recommended middleware components" off \
	EXTRAMID "Extra Middleware Components" off \
	TOOLS "Tools" off \
	CATALYST "Catalyst Engine" off \
	SQUATTING "Squatting::On" off \
	CGIAPP "CGI::Application::PSGI" off

.include <bsd.port.options.mk>

.if defined(WITH_FASTCGI)
DEP+=	p5-FastCGI>=0.71:${PORTSDIR}/www/p5-FastCGI \
	p5-FCGI-Client>=0.04:${PORTSDIR}/www/p5-FCGI-Client \
	p5-FCGI-ProcManager>=0.19:${PORTSDIR}/www/p5-FCGI-ProcManager \
	p5-Net-FastCGI>=0.11:${PORTSDIR}/www/p5-Net-FastCGI
.endif

.if defined(WITH_STACKTRACE)
DEP+=	p5-Devel-StackTrace-WithLexicals>=0.05:${PORTSDIR}/devel/p5-Devel-StackTrace-WithLexicals
.endif

.if defined(WITH_HANDLEIO)
DEP+=	p5-IO-Handle-Util>=0.01:${PORTSDIR}/devel/p5-IO-Handle-Util
.endif

.if defined(WITH_CORE)
DEP+=	p5-PSGI>=1.03:${PORTSDIR}/www/p5-PSGI \
	p5-Plack>=0.9934:${PORTSDIR}/www/p5-Plack \
	p5-CGI-PSGI>=0.11:${PORTSDIR}/www/p5-CGI-PSGI \
	p5-CGI-Emulate-PSGI>=0.08:${PORTSDIR}/www/p5-CGI-Emulate-PSGI \
	p5-CGI-Compile>=0.11:${PORTSDIR}/www/p5-CGI-Compile
.endif

.if defined(WITH_SERVER)
DEP+=	p5-HTTP-Server-Simple-PSGI>=0.14:${PORTSDIR}/www/p5-HTTP-Server-Simple-PSGI \
	p5-Starman>=0.2004:${PORTSDIR}/www/p5-Starman \
	p5-Twiggy>=0.1005:${PORTSDIR}/www/p5-Twiggy \
	p5-Starlet>=0.08:${PORTSDIR}/www/p5-Starlet \
	p5-Corona>=0.1004:${PORTSDIR}/www/p5-Corona
.endif

.if defined(WITH_EXTRASRV)
DEP+=	p5-POE-Component-Server-PSGI>=0.5:${PORTSDIR}/www/p5-POE-Component-Server-PSGI \
	p5-Plack-Handler-AnyEvent-ReverseHTTP>=0.04:${PORTSDIR}/www/p5-Plack-Handler-AnyEvent-ReverseHTTP \
	p5-Plack-Handler-SCGI>=0.02:${PORTSDIR}/www/p5-Plack-Handler-SCGI \
	p5-Plack-Handler-AnyEvent-SCGI>=0.02:${PORTSDIR}/www/p5-Plack-Handler-AnyEvent-SCGI \
	p5-Plack-Handler-AnyEvent-HTTPD>=0.01:${PORTSDIR}/www/p5-Plack-Handler-AnyEvent-HTTPD
.endif

.if defined(WITH_MIDDLE)
DEP+=	p5-Plack-Middleware-Deflater>=0.03:${PORTSDIR}/www/p5-Plack-Middleware-Deflater \
	p5-Plack-Middleware-Session>=0.11:${PORTSDIR}/www/p5-Plack-Middleware-Session \
	p5-Plack-Middleware-Debug>=0.09:${PORTSDIR}/www/p5-Plack-Middleware-Debug \
	p5-Plack-Middleware-Header>=0.03:${PORTSDIR}/www/p5-Plack-Middleware-Header \
	p5-Plack-Middleware-Auth-Digest>=0.03:${PORTSDIR}/www/p5-Plack-Middleware-Auth-Digest \
	p5-Plack-App-Proxy>=0.15:${PORTSDIR}/www/p5-Plack-App-Proxy \
	p5-Plack-Middleware-ReverseProxy>=0.06:${PORTSDIR}/www/p5-Plack-Middleware-ReverseProxy \
	p5-Plack-Middleware-ConsoleLogger>=0.01:${PORTSDIR}/www/p5-Plack-Middleware-ConsoleLogger
.endif

.if defined(WITH_EXTRAMID)
DEP+=	p5-Plack-Middleware-JSConcat>=0.29:${PORTSDIR}/www/p5-Plack-Middleware-JSConcat \
	p5-Plack-Middleware-File-Sass>=0.01:${PORTSDIR}/www/p5-Plack-Middleware-File-Sass
.endif

.if defined(WITH_TOOLS)
DEP+=	p5-Test-WWW-Mechanize-PSGI>=0.35:${PORTSDIR}/devel/p5-Test-WWW-Mechanize-PSGI
.endif

.if defined(WITH_CATALYST)
DEP+=	p5-Catalyst-Engine-PSGI>=0.09:${PORTSDIR}/www/p5-Catalyst-Engine-PSGI
.endif

.if defined(WITH_SQUATTING)
DEP+=	p5-Squatting-On-PSGI>=0.04:${PORTSDIR}/www/p5-Squatting-On-PSGI
.endif

.if defined(WITH_CGIAPP)
DEP+=	p5-CGI-Application-PSGI>=1.00:${PORTSDIR}/www/p5-CGI-Application-PSGI
.endif

BUILD_DEPENDS=	${DEP}
RUN_DEPENDS=	${DEP}

.include <bsd.port.mk>
