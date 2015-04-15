# Created by: vanilla
# $FreeBSD$

PORTNAME=	SOAP-Lite
PORTVERSION=	1.14
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	svysh.fbsd@gmail.com
COMMENT=	Client and server side SOAP implementation

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-Inspector>=0:${PORTSDIR}/devel/p5-Class-Inspector \
		p5-IO-SessionData>=1.03:${PORTSDIR}/devel/p5-IO-SessionData \
		p5-IO-Socket-SSL>=0:${PORTSDIR}/security/p5-IO-Socket-SSL \
		p5-LWP-Protocol-https>=0:${PORTSDIR}/www/p5-LWP-Protocol-https \
		p5-MIME-Tools>=0:${PORTSDIR}/mail/p5-MIME-Tools \
		p5-Task-Weaken>=0:${PORTSDIR}/devel/p5-Task-Weaken \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-XML-Parser>=2.23:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-XML-Parser-Lite>=0:${PORTSDIR}/textproc/p5-XML-Parser-Lite \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Warn>=0:${PORTSDIR}/devel/p5-Test-Warn \
		p5-Test-XML>=0:${PORTSDIR}/devel/p5-Test-XML

CONFLICTS=	p5-SOAP-Lite-0.60* p5-SOAP-[0-9]*

CONFIGURE_ARGS=	--noprompt
INSTALL_TARGET=	pure_install
USE_PERL5=	configure
USES=		perl5 shebangfix
NO_ARCH=	yes

SHEBANG_FILES=	bin/SOAPsh.pl
perl_OLD_CMD=	.*perl

.include <bsd.port.mk>
