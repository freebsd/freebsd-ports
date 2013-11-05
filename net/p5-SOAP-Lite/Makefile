# Created by: vanilla
# $FreeBSD$

PORTNAME=	SOAP-Lite
PORTVERSION=	0.716
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	SOAP::Lite - Client and server side SOAP implementation

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-Inspector>=0:${PORTSDIR}/devel/p5-Class-Inspector \
		p5-Crypt-SSLeay>=0:${PORTSDIR}/security/p5-Crypt-SSLeay \
		p5-MIME-Lite>=0:${PORTSDIR}/mail/p5-MIME-Lite \
		p5-MIME-Tools>=0:${PORTSDIR}/mail/p5-MIME-Tools \
		p5-Task-Weaken>=0:${PORTSDIR}/devel/p5-Task-Weaken \
		p5-XML-Parser>=2.23:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Devel-Cycle>=0:${PORTSDIR}/devel/p5-Devel-Cycle \
		p5-Test-MockObject>=0:${PORTSDIR}/devel/p5-Test-MockObject

CONFLICTS=	p5-SOAP-Lite-0.60* p5-SOAP-[0-9]*

CONFIGURE_ARGS=	--noprompt
INSTALL_TARGET=	pure_install
USE_PERL5=	configure
USES=		perl5 shebangfix

SHEBANG_FILES=	bin/* t/*.pl t/*.t
perl_OLD_CMD=	.*perl

.include <bsd.port.mk>
