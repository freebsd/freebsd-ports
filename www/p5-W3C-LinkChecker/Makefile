# Created by: Aaron Dalton <aaron@daltons.ca>
# $FreeBSD$

PORTNAME=	W3C-LinkChecker
PORTVERSION=	4.81
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SCOP
PKGNAMEPREFIX=	p5-

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	Checks the validity of links in an HTML or XHTML document

BUILD_DEPENDS=	p5-CSS-DOM>=0.09:${PORTSDIR}/www/p5-CSS-DOM \
		p5-Config-General>=0:${PORTSDIR}/devel/p5-Config-General \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-Net-IP>=0:${PORTSDIR}/net-mgmt/p5-Net-IP \
		p5-Term-ReadKey>=0:${PORTSDIR}/devel/p5-Term-ReadKey \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
