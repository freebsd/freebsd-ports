# Created by: Denny Lin <dennylin93@hs.ntnu.edu.tw>
# $FreeBSD$

PORTNAME=	App-gist
PORTVERSION=	0.14
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	GitHub Gist creator

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-App-Cmd>=0:${PORTSDIR}/devel/p5-App-Cmd \
		p5-Class-Load>=0:${PORTSDIR}/devel/p5-Class-Load \
		p5-Term-ReadKey>=0:${PORTSDIR}/devel/p5-Term-ReadKey \
		p5-WWW-GitHub-Gist>=0:${PORTSDIR}/www/p5-WWW-GitHub-Gist
RUN_DEPENDS:=	${BUILD_DEPENDS}

CONFLICTS=	gist-[0-9]*

USES=		perl5
USE_PERL5=	configure

MAN1=		gist.1
MAN3=		App::gist.3

.include <bsd.port.mk>
