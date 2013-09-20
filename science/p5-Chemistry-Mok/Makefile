# Created by: Steve Wills <steve@mouf.net>
# $FreeBSD$

PORTNAME=	Chemistry-Mok
PORTVERSION=	0.25
CATEGORIES=	science perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ITUB
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Molecular awk interpreter

BUILD_DEPENDS=	p5-Chemistry-Mol>=0:${PORTSDIR}/science/p5-Chemistry-Mol \
		p5-Chemistry-File-SMILES>=0:${PORTSDIR}/science/p5-Chemistry-File-SMILES \
		p5-Chemistry-Bond-Find>=0:${PORTSDIR}/science/p5-Chemistry-Bond-Find \
		p5-Chemistry-Pattern>=0:${PORTSDIR}/science/p5-Chemistry-Pattern
RUN_DEPENDS=	p5-Chemistry-Mol>=0:${PORTSDIR}/science/p5-Chemistry-Mol \
		p5-Chemistry-File-SMILES>=0:${PORTSDIR}/science/p5-Chemistry-File-SMILES \
		p5-Chemistry-Bond-Find>=0:${PORTSDIR}/science/p5-Chemistry-Bond-Find \
		p5-Chemistry-Pattern>=0:${PORTSDIR}/science/p5-Chemistry-Pattern

MAN1=	mok.1
MAN3=	Chemistry::Mok.3

USES=		perl5
USE_PERL5=	configure

NO_STAGE=	yes
.include <bsd.port.mk>
