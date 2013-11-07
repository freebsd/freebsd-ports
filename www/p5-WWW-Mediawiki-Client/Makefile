# Created by: ijliao
# $FreeBSD$

PORTNAME=	WWW-Mediawiki-Client
PORTVERSION=	0.31
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Very simple cvs-like interface for Mediawiki websites

BUILD_DEPENDS=	p5-Test-Differences>0:${PORTSDIR}/devel/p5-Test-Differences \
		p5-VCS-Lite>0:${PORTSDIR}/devel/p5-VCS-Lite \
		p5-libwww>0:${PORTSDIR}/www/p5-libwww \
		p5-HTML-Parser>0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-XML-LibXML>0:${PORTSDIR}/textproc/p5-XML-LibXML \
		p5-URI>=1.31:${PORTSDIR}/net/p5-URI \
		p5-Exception-Class>0:${PORTSDIR}/devel/p5-Exception-Class
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
