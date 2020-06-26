# Created by: Aaron Straup Cope <ascope@cpan.org>
# $FreeBSD$

PORTNAME=	Net-Delicious
PORTVERSION=	1.14
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	OOP for managing posts on del.icio.us

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Config-Simple>=2:devel/p5-Config-Simple \
		p5-Crypt-SSLeay>=0:security/p5-Crypt-SSLeay \
		p5-IO-Stringy>=2.1:devel/p5-IO-Stringy \
		p5-Log-Dispatch>=2:devel/p5-Log-Dispatch \
		p5-TimeDate>=2.27:devel/p5-TimeDate \
		p5-URI>=0:net/p5-URI \
		p5-XML-Simple>=2:textproc/p5-XML-Simple \
		p5-YAML>=0.35:textproc/p5-YAML \
		p5-libwww>=0:www/p5-libwww

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
