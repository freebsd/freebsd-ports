# Created by: Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
# $FreeBSD$

PORTNAME=	POE-Component-Server-NNTP
PORTVERSION=	1.06
CATEGORIES=	news perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Component that provides NNTP server functionality

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-POE>=0.38:devel/p5-POE \
		p5-POE-Component-Client-NNTP>=1.05:news/p5-POE-Component-Client-NNTP \
		p5-POE-Component-Pluggable>=0.03:devel/p5-POE-Component-Pluggable
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
