# New ports collection makefile for:	POE-Filter-SSL
# Date created:	   December 22, 2010
# Whom:		   mat
#
# $FreeBSD$
#

PORTNAME=	POE-Filter-SSL
PORTVERSION=	0.24
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PRIVI
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	The easiest and flexiblest way to SSL in POEIntegrate SSL into POE

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Net-SSLeay>=0:${PORTSDIR}/security/p5-Net-SSLeay \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-POE>=0:${PORTSDIR}/devel/p5-POE \
		p5-Test-Simple>=0:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	p5-Net-SSLeay>=0:${PORTSDIR}/security/p5-Net-SSLeay \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-POE>=0:${PORTSDIR}/devel/p5-POE

WRKSRC=	${WRKDIR}

USES=		perl5
USE_PERL5=	configure

MAN3=		POE::Filter::SSL.3

.include <bsd.port.mk>
