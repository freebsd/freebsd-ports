# Created by: Tsung-Han Yeh <snowfly@yuntech.edu.tw>
# $FreeBSD$

PORTNAME=	NetApp
PORTVERSION=	500.002
PORTREVISION=	1
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	snowfly@yuntech.edu.tw
COMMENT=	Perl interface to manage NetApp NAS devices

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-Std>=0:devel/p5-Class-Std \
		p5-Clone>=0:devel/p5-Clone \
		p5-IPC-Cmd>=0:devel/p5-IPC-Cmd \
		p5-Net-Telnet>=0:net/p5-Net-Telnet \
		p5-Params-Validate>=0:devel/p5-Params-Validate \
		p5-Regexp-Common>=0:textproc/p5-Regexp-Common
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
