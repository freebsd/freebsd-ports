# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Text-Table-More
PORTVERSION=	0.011
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Generate text table with simple interface and many options

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-File-ShareDir-Install>=0.06:devel/p5-File-ShareDir-Install \
		${RUN_DEPENDS}
RUN_DEPENDS=	p5-BorderStyles-Standard>=0:devel/p5-BorderStyles-Standard \
		p5-List-AllUtils>=0:devel/p5-List-AllUtils \
		p5-Module-Load-Util>=0.004:devel/p5-Module-Load-Util \
		p5-String-Pad>=0:textproc/p5-String-Pad \
		p5-Text-NonWideChar-Util>=0:textproc/p5-Text-NonWideChar-Util

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
