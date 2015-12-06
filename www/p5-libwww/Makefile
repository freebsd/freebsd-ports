# Created by: James FitzGibbon <jfitz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libwww
PORTVERSION=	6.15
DISTVERSIONPREFIX=	perl-
CATEGORIES=	www devel perl5
MASTER_SITES=	CPAN/LWP
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl5 library for WWW access

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Authen-NTLM>=1.02:${PORTSDIR}/security/p5-Authen-NTLM \
		p5-Encode-Locale>=0:${PORTSDIR}/converters/p5-Encode-Locale \
		p5-File-Listing>=6:${PORTSDIR}/sysutils/p5-File-Listing \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-HTTP-Cookies>=6:${PORTSDIR}/www/p5-HTTP-Cookies \
		p5-HTTP-Daemon>=6:${PORTSDIR}/www/p5-HTTP-Daemon \
		p5-HTTP-Date>=6:${PORTSDIR}/www/p5-HTTP-Date \
		p5-HTTP-Message>=6:${PORTSDIR}/www/p5-HTTP-Message \
		p5-HTTP-Negotiate>=6:${PORTSDIR}/www/p5-HTTP-Negotiate \
		p5-LWP-MediaTypes>=6:${PORTSDIR}/www/p5-LWP-MediaTypes \
		p5-Net-HTTP>=6.07:${PORTSDIR}/net/p5-Net-HTTP \
		p5-URI>=1.10:${PORTSDIR}/net/p5-URI \
		p5-WWW-RobotRules>=6:${PORTSDIR}/www/p5-WWW-RobotRules
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	HTTPS

CONFIGURE_ARGS=	--aliases
USE_PERL5=	configure
USES=		perl5

HTTPS_BUILD_DEPENDS=	p5-LWP-Protocol-https>=0:${PORTSDIR}/www/p5-LWP-Protocol-https
HTTPS_RUN_DEPENDS=	p5-LWP-Protocol-https>=0:${PORTSDIR}/www/p5-LWP-Protocol-https

.include <bsd.port.mk>
