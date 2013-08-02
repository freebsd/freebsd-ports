# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Algorithm-SVMLight
PORTVERSION=	0.09
CATEGORIES=	science perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to SVMLight Machine-Learning Package

BUILD_DEPENDS=	svmlight>=6.01_2:${PORTSDIR}/science/svmlight
LIB_DEPENDS=	svmlight:${PORTSDIR}/science/svmlight

USES=		perl5
USE_PERL5=	modbuild

MAN3=		Algorithm::SVMLight.3

post-patch:
	@${REINPLACE_CMD} -e "s,%%LOCALBASE%%,${LOCALBASE},g" \
		${WRKSRC}/Build.PL

.include <bsd.port.mk>
