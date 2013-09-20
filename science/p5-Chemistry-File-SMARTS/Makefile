# Created by: Steve Wills <steve@mouf.net>
# $FreeBSD$

PORTNAME=	Chemistry-File-SMARTS
PORTVERSION=	0.22
CATEGORIES=	science perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ITUB
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	SMARTS chemical substructure pattern linear notation parser

BUILD_DEPENDS=	p5-Chemistry-Mol>=0:${PORTSDIR}/science/p5-Chemistry-Mol \
		p5-Chemistry-Ring>=0:${PORTSDIR}/science/p5-Chemistry-Ring \
		p5-Chemistry-Pattern>=0:${PORTSDIR}/science/p5-Chemistry-Pattern \
		p5-Chemistry-File-SMILES>=0:${PORTSDIR}/science/p5-Chemistry-File-SMILES
RUN_DEPENDS=	p5-Chemistry-Mol>=0:${PORTSDIR}/science/p5-Chemistry-Mol \
		p5-Chemistry-Ring>=0:${PORTSDIR}/science/p5-Chemistry-Ring \
		p5-Chemistry-Pattern>=0:${PORTSDIR}/science/p5-Chemistry-Pattern \
		p5-Chemistry-File-SMILES>=0:${PORTSDIR}/science/p5-Chemistry-File-SMILES

MAN3=	Chemistry::File::SMARTS.3

USES=		perl5
USE_PERL5=	configure

NO_STAGE=	yes
.include <bsd.port.mk>
