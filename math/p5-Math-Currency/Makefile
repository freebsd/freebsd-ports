# New ports collection makefile for:	Math-Currency
# Date created:				Wed Jan  3 10:58:59 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	Math-Currency
PORTVERSION=	0.40
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Math
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Perl module for exact currency math with formatting and rounding

BUILD_DEPENDS=	${SITE_PERL}/Math/FixedPrecision.pm:${PORTSDIR}/math/p5-Math-FixedPrecision \
		${SITE_PERL}/Math/BigFloat.pm:${PORTSDIR}/math/p5-Math-BigInt \
		${SITE_PERL}/${PERL_ARCH}/Scalar/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		Math::Currency.3

.if !defined(NOPORTDOCS)
PORTDOCS=	Changes

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
