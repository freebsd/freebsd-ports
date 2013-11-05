# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	FLV-Info
PORTVERSION=	0.24
CATEGORIES=	multimedia perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:CDOLAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Extract metadata from Flash Video files

BUILD_DEPENDS=	p5-AMF-Perl>=0.15:${PORTSDIR}/www/p5-AMF-Perl \
		p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Readonly>=0:${PORTSDIR}/devel/p5-Readonly \
		p5-SWF-File>=0.033:${PORTSDIR}/graphics/p5-SWF-File
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
