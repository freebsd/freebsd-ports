# Created by: Steve Wills <steve@mouf.net>
# $FreeBSD$

PORTNAME=	Chemistry-File-SMILES
PORTVERSION=	0.47
CATEGORIES=	science perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ITUB
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	SMILES linear notation parser/writer

BUILD_DEPENDS=	p5-Chemistry-Mol>=0:${PORTSDIR}/science/p5-Chemistry-Mol \
		p5-Chemistry-Bond-Find>=0:${PORTSDIR}/science/p5-Chemistry-Bond-Find \
		p5-Chemistry-Canonicalize>=0:${PORTSDIR}/science/p5-Chemistry-Canonicalize \
		p5-Chemistry-Ring>=0:${PORTSDIR}/science/p5-Chemistry-Ring
RUN_DEPENDS=	p5-Chemistry-Mol>=0:${PORTSDIR}/science/p5-Chemistry-Mol \
		p5-Chemistry-Bond-Find>=0:${PORTSDIR}/science/p5-Chemistry-Bond-Find \
		p5-Chemistry-Canonicalize>=0:${PORTSDIR}/science/p5-Chemistry-Canonicalize \
		p5-Chemistry-Ring>=0:${PORTSDIR}/science/p5-Chemistry-Ring

MAN3=	Chemistry::File::SMILES.3

USES=		perl5
USE_PERL5=	configure

NO_STAGE=	yes
.include <bsd.port.mk>
