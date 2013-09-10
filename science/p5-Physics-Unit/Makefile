# Created by: Frederic Culot <frederic@culot.org>
# $FreeBSD$

PORTNAME=	Physics-Unit
PORTVERSION=	0.53
CATEGORIES=	science perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Manipulate Physics units and dimensions

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	modbuild

MAN1=		physics-unit.1
MAN3=		Physics::Unit.3 \
		Physics::Unit::Implementation.3 \
		Physics::Unit::Scalar.3 \
		Physics::Unit::Scalar::Implementation.3 \
		Physics::Unit::UnitsByName.3 \
		Physics::Unit::UnitsByType.3

post-install:
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/eg/ && ${COPYTREE_SHARE} '*.pl' ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
