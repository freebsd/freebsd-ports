# $FreeBSD$

PORTNAME=	Text-ClearSilver
PORTVERSION=	0.10.5.4
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to the ClearSilver template engine

TEST_DEPENDS=	\
	p5-Test-Requires>0:${PORTSDIR}/devel/p5-Test-Requires \
	p5-Mouse>0:${PORTSDIR}/devel/p5-Mouse

USES=		perl5
USE_PERL5=	configure
USE_GMAKE=	yes
CONFIGURE_ENV=	MAKE=${LOCALBASE}/bin/gmake

MAN3=	Text::ClearSilver.3 \
	Text::ClearSilver::Compat.3 \
	Text::ClearSilver::FunctionSet.3 \
	Text::ClearSilver::FunctionSet::html.3 \
	Text::ClearSilver::FunctionSet::string.3

NO_STAGE=	yes
.include <bsd.port.mk>
