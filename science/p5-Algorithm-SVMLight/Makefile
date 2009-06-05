# New ports collection makefile for:	p5-Algorithm-SVMLight
# Date created:		2006-07-18
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Algorithm-SVMLight
PORTVERSION=	0.09
CATEGORIES=	science perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Perl interface to SVMLight Machine-Learning Package

BUILD_DEPENDS=	svmlight>=6.01_2:${PORTSDIR}/science/svmlight
LIB_DEPENDS=	svmlight:${PORTSDIR}/science/svmlight

PERL_MODBUILD=	yes

MAN3=		Algorithm::SVMLight.3

post-patch:
	@${REINPLACE_CMD} -e "s,%%LOCALBASE%%,${LOCALBASE},g" \
		${WRKSRC}/Build.PL

.include <bsd.port.mk>
