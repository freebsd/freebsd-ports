# New ports collection makefile for:	FormValidator::Simple
# Date created:				21 Nov 2005
# Whom:					Lars Balker Rasmussen <lars@balker.dk>
#
# $FreeBSD$
#

PORTNAME=		FormValidator-Simple
PORTVERSION=		0.15
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/L/LY/LYOKATO
PKGNAMEPREFIX=		p5-

MAINTAINER=		lars@balker.dk
COMMENT=		Validation with simple chains of constraints

BUILD_DEPENDS=	p5-Class-Accessor>=0.22:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Class-Data-Inheritable>=0.04:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		p5-Class-Inspector>=1.13:${PORTSDIR}/devel/p5-Class-Inspector \
		p5-Date-Calc>=5.4:${PORTSDIR}/devel/p5-Date-Calc \
		p5-Email-Valid>=0.15:${PORTSDIR}/mail/p5-Email-Valid \
		p5-Email-Valid-Loose>=0.04:${PORTSDIR}/mail/p5-Email-Valid-Loose \
		p5-List-MoreUtils>=0.16:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Scalar-List-Utils>=0:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		p5-Mail-Tools>=0:${PORTSDIR}/mail/p5-Mail-Tools \
		p5-Tie-IxHash>=1.21:${PORTSDIR}/devel/p5-Tie-IxHash \
		p5-UNIVERSAL-require>=0.10:${PORTSDIR}/devel/p5-UNIVERSAL-require \
		p5-YAML>=0.39:${PORTSDIR}/textproc/p5-YAML
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		FormValidator::Simple.3 \
		FormValidator::Simple::Results.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		requires perl 5.8 or later. Install lang/perl5.8 then try again
.endif

.include <bsd.port.post.mk>
