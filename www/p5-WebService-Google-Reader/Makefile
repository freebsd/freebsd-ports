# Created by: Frederic Culot <frederic@culot.org>
# $FreeBSD$

PORTNAME=	WebService-Google-Reader
PORTVERSION=	0.23
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Perl interface to Google Reader

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-JSON-XS>=2:converters/p5-JSON-XS \
		p5-URI>=1.36:net/p5-URI \
		p5-libwww>=6.02:www/p5-libwww \
		p5-LWP-Protocol-https>=6.02:www/p5-LWP-Protocol-https \
		p5-HTTP-Message>=6:www/p5-HTTP-Message \
		p5-HTTP-Date>=6:www/p5-HTTP-Date \
		p5-Class-Accessor>0:devel/p5-Class-Accessor \
		p5-Crypt-SSLeay>0:security/p5-Crypt-SSLeay \
		p5-JSON>=2:converters/p5-JSON \
		p5-XML-Atom>0:textproc/p5-XML-Atom \
		p5-XML-LibXML>0:textproc/p5-XML-LibXML
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
