# $FreeBSD$

PORTNAME=	Task-Plack
PORTVERSION=	0.25
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl module bundle for Plack

USES=		perl5
USE_PERL5=	configure

OPTIONS_DEFINE=	FASTCGI STACKTRACE HANDLEIO CORE SERVER EXTRASRV MIDDLE \
		EXTRAMID TOOLS CATALYST SQUATTING CGIAPP
OPTIONS_DEFAULT=	CORE

FASTCGI_DESC=		FastCGI daemon and dispatcher
STACKTRACE_DESC=	Stacktrace with lexical variables
HANDLEIO_DESC=		Utility to create IO::Handle-ish objects
CORE_DESC=		Core and Essential Tools
SERVER_DESC=		Recommended PSGI Servers and Plack handlers
EXTRASRV_DESC=		Extra PSGI servers and Plack handlers
MIDDLE_DESC=		Recommended middleware components
EXTRAMID_DESC=		Extra Middleware Components
TOOLS_DESC=		Tools
CATALYST_DESC=		Catalyst Engine
SQUATTING_DESC=		Squatting::On
CGIAPP_DESC=		CGI::Application::PSGI
#OPTIONS:=${OPTIONS:C/off/on/g}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFASTCGI}
DEP+=	p5-FCGI>=0.71:www/p5-FCGI \
	p5-FCGI-Client>=0.04:www/p5-FCGI-Client \
	p5-FCGI-ProcManager>=0.19:www/p5-FCGI-ProcManager \
	p5-Net-FastCGI>=0.11:www/p5-Net-FastCGI
.endif

.if ${PORT_OPTIONS:MSTACKTRACE}
DEP+=	p5-Devel-StackTrace-WithLexicals>=0.05:devel/p5-Devel-StackTrace-WithLexicals
.endif

.if ${PORT_OPTIONS:MHANDLEIO}
DEP+=	p5-IO-Handle-Util>=0.01:devel/p5-IO-Handle-Util
.endif

.if ${PORT_OPTIONS:MCORE}
DEP+=	p5-PSGI>=1.03:www/p5-PSGI \
	p5-Plack>=0.9934:www/p5-Plack \
	p5-CGI-PSGI>=0.11:www/p5-CGI-PSGI \
	p5-CGI-Emulate-PSGI>=0.08:www/p5-CGI-Emulate-PSGI \
	p5-CGI-Compile>=0.11:www/p5-CGI-Compile
.endif

.if ${PORT_OPTIONS:MSERVER}
DEP+=	p5-HTTP-Server-Simple-PSGI>=0.14:www/p5-HTTP-Server-Simple-PSGI \
	p5-Starman>=0.2004:www/p5-Starman \
	p5-Twiggy>=0.1005:www/p5-Twiggy \
	p5-Starlet>=0.08:www/p5-Starlet \
	p5-Corona>=0.1004:www/p5-Corona
.endif

.if ${PORT_OPTIONS:MEXTRASRV}
DEP+=	p5-POE-Component-Server-PSGI>=0.5:www/p5-POE-Component-Server-PSGI \
	p5-Plack-Handler-AnyEvent-ReverseHTTP>=0.04:www/p5-Plack-Handler-AnyEvent-ReverseHTTP \
	p5-Plack-Handler-SCGI>=0.02:www/p5-Plack-Handler-SCGI \
	p5-Plack-Handler-AnyEvent-SCGI>=0.02:www/p5-Plack-Handler-AnyEvent-SCGI \
	p5-Plack-Handler-AnyEvent-HTTPD>=0.01:www/p5-Plack-Handler-AnyEvent-HTTPD \
	p5-Perlbal-Plugin-PSGI>=0.03:www/p5-Perlbal-Plugin-PSGI
#	p5-Plack-Handler-Mongrel2>0:www/p5-Plack-Handler-Mongrel2
.endif

.if ${PORT_OPTIONS:MMIDDLE}
DEP+=	p5-Plack-Middleware-Deflater>=0.03:www/p5-Plack-Middleware-Deflater \
	p5-Plack-Middleware-Session>=0.11:www/p5-Plack-Middleware-Session \
	p5-Plack-Middleware-Debug>=0.09:www/p5-Plack-Middleware-Debug \
	p5-Plack-Middleware-Header>=0.03:www/p5-Plack-Middleware-Header \
	p5-Plack-Middleware-Auth-Digest>=0.03:www/p5-Plack-Middleware-Auth-Digest \
	p5-Plack-App-Proxy>=0.15:www/p5-Plack-App-Proxy \
	p5-Plack-Middleware-ReverseProxy>=0.06:www/p5-Plack-Middleware-ReverseProxy \
	p5-Plack-Middleware-ConsoleLogger>=0.01:www/p5-Plack-Middleware-ConsoleLogger
.endif

.if ${PORT_OPTIONS:MEXTRAMID}
DEP+=	p5-Plack-Middleware-JSConcat>=0.29:www/p5-Plack-Middleware-JSConcat \
	p5-Plack-Middleware-Throttle>=0.01:www/p5-Plack-Middleware-Throttle \
	p5-Plack-Middleware-Status>=1.101150:www/p5-Plack-Middleware-Status \
	p5-Plack-Middleware-AutoRefresh>=0.08:www/p5-Plack-Middleware-AutoRefresh \
	p5-Plack-Middleware-File-Sass>=0.01:www/p5-Plack-Middleware-File-Sass
.endif

.if ${PORT_OPTIONS:MTOOLS}
DEP+=	p5-Test-WWW-Mechanize-PSGI>=0.35:devel/p5-Test-WWW-Mechanize-PSGI \
	p5-Flea>=0.02:www/p5-Flea
.endif

.if ${PORT_OPTIONS:MCATALYST}
DEP+=	p5-Catalyst-Engine-PSGI>=0.09:www/p5-Catalyst-Engine-PSGI
.endif

.if ${PORT_OPTIONS:MSQUATTING}
DEP+=	p5-Squatting-On-PSGI>=0.04:www/p5-Squatting-On-PSGI
.endif

.if ${PORT_OPTIONS:MCGIAPP}
DEP+=	p5-CGI-Application-PSGI>=1.00:www/p5-CGI-Application-PSGI
.endif

BUILD_DEPENDS=	${DEP}
RUN_DEPENDS=	${DEP}

.include <bsd.port.mk>
