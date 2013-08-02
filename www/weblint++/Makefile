# Created by: aaron@FreeBSD.org
# $FreeBSD$

PORTNAME=	weblint++
PORTVERSION=	1.15
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BDFOY

MAINTAINER=	perl@FreeBSD.org
COMMENT=	HTML validator and sanity checker

BUILD_DEPENDS=	p5-ConfigReader-Simple>=1.15:${PORTSDIR}/devel/p5-ConfigReader-Simple \
		p5-File-Find-Rule>0:${PORTSDIR}/devel/p5-File-Find-Rule \
		p5-HTML-Lint>0:${PORTSDIR}/www/p5-HTML-Lint \
		p5-HTML-SimpleLinkExtor>0:${PORTSDIR}/www/p5-HTML-SimpleLinkExtor \
		p5-libwww>0:${PORTSDIR}/www/p5-libwww \
		p5-HTTP-SimpleLinkChecker>0:${PORTSDIR}/www/p5-HTTP-SimpleLinkChecker \
		p5-HTTP-Size>=0.04:${PORTSDIR}/www/p5-HTTP-Size \
		p5-Mail-Sendmail>0:${PORTSDIR}/mail/p5-Mail-Sendmail \
		p5-Test-Manifest>0.91:${PORTSDIR}/devel/p5-Test-Manifest \
		p5-Test-Pod>=0.90:${PORTSDIR}/devel/p5-Test-Pod \
		p5-Text-Diff>0:${PORTSDIR}/textproc/p5-Text-Diff \
		p5-Text-Template>0:${PORTSDIR}/textproc/p5-Text-Template \
		p5-Test-File>0:${PORTSDIR}/devel/p5-Test-File \
		p5-URI>0:${PORTSDIR}/net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN1=		weblint++.1

.include <bsd.port.mk>
