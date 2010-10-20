# New ports collection makefile for:	Physics-Unit
# Date created:				2010-09-03
# Whom:					Frederic Culot <frederic@culot.org>
#
# $FreeBSD$
#

PORTNAME=	Physics-Unit
PORTVERSION=	0.04
CATEGORIES=	science perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Manipulate Physics units and dimensions

PERL_CONFIGURE=	yes

MAN3=		Physics::Unit.3 Physics::UnitImpl.3 Physics::Unit::Scalar.3 \
		Physics::Unit::ScalarImpl.3 Physics::Unit::ScalarSubtypes.3 \
		Physics::Unit::Vector.3

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.html ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/eg/ && ${COPYTREE_SHARE} '*.pl' ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
