# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	ODF-lpOD
PORTVERSION=	1.121
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	OpenDocument management interface

BUILD_DEPENDS=	p5-Archive-Zip>=1.30:${PORTSDIR}/archivers/p5-Archive-Zip \
		p5-XML-Twig>=3.37:${PORTSDIR}/textproc/p5-XML-Twig \
		p5-File-Type>=0:${PORTSDIR}/devel/p5-File-Type \
		p5-Image-Size>=0:${PORTSDIR}/graphics/p5-Image-Size \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
