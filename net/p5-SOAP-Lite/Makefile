# Created by: vanilla
# $FreeBSD$

PORTNAME=	SOAP-Lite
PORTVERSION=	1.19
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	svysh.fbsd@gmail.com
COMMENT=	Client and server side SOAP implementation

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Class-Inspector>=0:devel/p5-Class-Inspector \
		p5-IO-SessionData>=1.03:devel/p5-IO-SessionData \
		p5-IO-Socket-SSL>=0:security/p5-IO-Socket-SSL \
		p5-LWP-Protocol-https>=0:www/p5-LWP-Protocol-https \
		p5-MIME-Tools>=0:mail/p5-MIME-Tools \
		p5-Task-Weaken>=0:devel/p5-Task-Weaken \
		p5-URI>=0:net/p5-URI \
		p5-XML-Parser>=2.23:textproc/p5-XML-Parser \
		p5-XML-Parser-Lite>=0:textproc/p5-XML-Parser-Lite \
		p5-libwww>=0:www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Warn>=0:devel/p5-Test-Warn \
		p5-Test-XML>=0:devel/p5-Test-XML

CONFLICTS_INSTALL=	p5-SOAP-Lite-0.60* p5-SOAP-[0-9]*

CONFIGURE_ARGS=	--noprompt
INSTALL_TARGET=	pure_install
USE_PERL5=	configure
USES=		perl5 shebangfix
NO_ARCH=	yes

SHEBANG_FILES=	bin/SOAPsh.pl
perl_OLD_CMD=	.*perl

.include <bsd.port.mk>
