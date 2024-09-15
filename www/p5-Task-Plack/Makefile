PORTNAME=	Task-Plack
PORTVERSION=	0.28
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module bundle for Plack
WWW=		https://metacpan.org/release/Task-Plack

USES=		perl5
USE_PERL5=	modbuildtiny

NO_ARCH=	yes

OPTIONS_DEFINE=	CATALYST CGIAPP CORE EXTRAMID EXTRASRV FASTCGI HANDLEIO MIDDLE SERVER SQUATTING STACKTRACE
OPTIONS_DEFAULT=CORE
CATALYST_DESC=	Catalyst Engine
CGIAPP_DESC=	CGI::Application::PSGI
CORE_DESC=	Core and Essential Tools
EXTRAMID_DESC=	Extra Middleware Components
EXTRASRV_DESC=	Extra PSGI servers and Plack handlers
FASTCGI_DESC=	FastCGI daemon and dispatcher
HANDLEIO_DESC=	Utility to create IO::Handle-ish objects
MIDDLE_DESC=	Recommended middleware components
SERVER_DESC=	Recommended PSGI Servers and Plack handlers
SQUATTING_DESC=	Squatting::On
STACKTRACE_DESC=Stacktrace with lexical variables

CATALYST_BUILD_DEPENDS=	p5-Catalyst-Engine-PSGI>=0.09:www/p5-Catalyst-Engine-PSGI
CATALYST_RUN_DEPENDS=	p5-Catalyst-Engine-PSGI>=0.09:www/p5-Catalyst-Engine-PSGI
CGIAPP_BUILD_DEPENDS=	p5-CGI-Application-PSGI>=1.00:www/p5-CGI-Application-PSGI
CGIAPP_RUN_DEPENDS=	p5-CGI-Application-PSGI>=1.00:www/p5-CGI-Application-PSGI
CORE_BUILD_DEPENDS=	p5-CGI-Compile>=0.11:www/p5-CGI-Compile \
			p5-CGI-Emulate-PSGI>=0.08:www/p5-CGI-Emulate-PSGI \
			p5-CGI-PSGI>=0.11:www/p5-CGI-PSGI \
			p5-PSGI>=1.03:www/p5-PSGI \
			p5-Plack>=0.9934:www/p5-Plack
CORE_RUN_DEPENDS=	p5-CGI-Compile>=0.11:www/p5-CGI-Compile \
			p5-CGI-Emulate-PSGI>=0.08:www/p5-CGI-Emulate-PSGI \
			p5-CGI-PSGI>=0.11:www/p5-CGI-PSGI \
			p5-PSGI>=1.03:www/p5-PSGI \
			p5-Plack>=0.9934:www/p5-Plack
EXTRAMID_BUILD_DEPENDS=	p5-Plack-Middleware-AutoRefresh>=0.08:www/p5-Plack-Middleware-AutoRefresh \
			p5-Plack-Middleware-File-Sass>=0.01:www/p5-Plack-Middleware-File-Sass \
			p5-Plack-Middleware-JSConcat>=0.29:www/p5-Plack-Middleware-JSConcat \
			p5-Plack-Middleware-Status>=1.101150:www/p5-Plack-Middleware-Status \
			p5-Plack-Middleware-Throttle>=0.01:www/p5-Plack-Middleware-Throttle
EXTRAMID_RUN_DEPENDS=	p5-Plack-Middleware-AutoRefresh>=0.08:www/p5-Plack-Middleware-AutoRefresh \
			p5-Plack-Middleware-File-Sass>=0.01:www/p5-Plack-Middleware-File-Sass \
			p5-Plack-Middleware-JSConcat>=0.29:www/p5-Plack-Middleware-JSConcat \
			p5-Plack-Middleware-Status>=1.101150:www/p5-Plack-Middleware-Status \
			p5-Plack-Middleware-Throttle>=0.01:www/p5-Plack-Middleware-Throttle
EXTRASRV_BUILD_DEPENDS=	p5-POE-Component-Server-PSGI>=0.5:www/p5-POE-Component-Server-PSGI \
			p5-Perlbal-Plugin-PSGI>=0.03:www/p5-Perlbal-Plugin-PSGI \
			p5-Plack-Handler-AnyEvent-HTTPD>=0.01:www/p5-Plack-Handler-AnyEvent-HTTPD \
			p5-Plack-Handler-AnyEvent-ReverseHTTP>=0.04:www/p5-Plack-Handler-AnyEvent-ReverseHTTP \
			p5-Plack-Handler-AnyEvent-SCGI>=0.02:www/p5-Plack-Handler-AnyEvent-SCGI \
			p5-Plack-Handler-SCGI>=0.02:www/p5-Plack-Handler-SCGI
EXTRASRV_RUN_DEPENDS=	p5-POE-Component-Server-PSGI>=0.5:www/p5-POE-Component-Server-PSGI \
			p5-Perlbal-Plugin-PSGI>=0.03:www/p5-Perlbal-Plugin-PSGI \
			p5-Plack-Handler-AnyEvent-HTTPD>=0.01:www/p5-Plack-Handler-AnyEvent-HTTPD \
			p5-Plack-Handler-AnyEvent-ReverseHTTP>=0.04:www/p5-Plack-Handler-AnyEvent-ReverseHTTP \
			p5-Plack-Handler-AnyEvent-SCGI>=0.02:www/p5-Plack-Handler-AnyEvent-SCGI \
			p5-Plack-Handler-SCGI>=0.02:www/p5-Plack-Handler-SCGI
FASTCGI_BUILD_DEPENDS=	p5-FCGI>=0.71:www/p5-FCGI \
			p5-FCGI-Client>=0.04:www/p5-FCGI-Client \
			p5-FCGI-ProcManager>=0.19:www/p5-FCGI-ProcManager \
			p5-Net-FastCGI>=0.11:www/p5-Net-FastCGI
FASTCGI_RUN_DEPENDS=	p5-FCGI>=0.71:www/p5-FCGI \
			p5-FCGI-Client>=0.04:www/p5-FCGI-Client \
			p5-FCGI-ProcManager>=0.19:www/p5-FCGI-ProcManager \
			p5-Net-FastCGI>=0.11:www/p5-Net-FastCGI
HANDLEIO_BUILD_DEPENDS=	p5-IO-Handle-Util>=0.01:devel/p5-IO-Handle-Util
HANDLEIO_RUN_DEPENDS=	p5-IO-Handle-Util>=0.01:devel/p5-IO-Handle-Util
MIDDLE_BUILD_DEPENDS=	p5-Plack-App-Proxy>=0.15:www/p5-Plack-App-Proxy \
			p5-Plack-Middleware-Auth-Digest>=0.03:www/p5-Plack-Middleware-Auth-Digest \
			p5-Plack-Middleware-ConsoleLogger>=0.01:www/p5-Plack-Middleware-ConsoleLogger \
			p5-Plack-Middleware-Debug>=0.09:www/p5-Plack-Middleware-Debug \
			p5-Plack-Middleware-Deflater>=0.03:www/p5-Plack-Middleware-Deflater \
			p5-Plack-Middleware-Header>=0.03:www/p5-Plack-Middleware-Header \
			p5-Plack-Middleware-ReverseProxy>=0.06:www/p5-Plack-Middleware-ReverseProxy \
			p5-Plack-Middleware-Session>=0.11:www/p5-Plack-Middleware-Session
MIDDLE_RUN_DEPENDS=	p5-Plack-App-Proxy>=0.15:www/p5-Plack-App-Proxy \
			p5-Plack-Middleware-Auth-Digest>=0.03:www/p5-Plack-Middleware-Auth-Digest \
			p5-Plack-Middleware-ConsoleLogger>=0.01:www/p5-Plack-Middleware-ConsoleLogger \
			p5-Plack-Middleware-Debug>=0.09:www/p5-Plack-Middleware-Debug \
			p5-Plack-Middleware-Deflater>=0.03:www/p5-Plack-Middleware-Deflater \
			p5-Plack-Middleware-Header>=0.03:www/p5-Plack-Middleware-Header \
			p5-Plack-Middleware-ReverseProxy>=0.06:www/p5-Plack-Middleware-ReverseProxy \
			p5-Plack-Middleware-Session>=0.11:www/p5-Plack-Middleware-Session
SERVER_BUILD_DEPENDS=	p5-Corona>=0.1004:www/p5-Corona \
			p5-HTTP-Server-Simple-PSGI>=0.14:www/p5-HTTP-Server-Simple-PSGI \
			p5-Starlet>=0.08:www/p5-Starlet \
			p5-Starman>=0.2004:www/p5-Starman \
			p5-Twiggy>=0.1005:www/p5-Twiggy
SERVER_RUN_DEPENDS=	p5-Corona>=0.1004:www/p5-Corona \
			p5-HTTP-Server-Simple-PSGI>=0.14:www/p5-HTTP-Server-Simple-PSGI \
			p5-Starlet>=0.08:www/p5-Starlet \
			p5-Starman>=0.2004:www/p5-Starman \
			p5-Twiggy>=0.1005:www/p5-Twiggy
SQUATTING_BUILD_DEPENDS=p5-Squatting-On-PSGI>=0.04:www/p5-Squatting-On-PSGI
SQUATTING_RUN_DEPENDS=	p5-Squatting-On-PSGI>=0.04:www/p5-Squatting-On-PSGI
STACKTRACE_BUILD_DEPENDS=	p5-Devel-StackTrace-WithLexicals>=0.05:devel/p5-Devel-StackTrace-WithLexicals
STACKTRACE_RUN_DEPENDS=	p5-Devel-StackTrace-WithLexicals>=0.05:devel/p5-Devel-StackTrace-WithLexicals

.include <bsd.port.mk>
