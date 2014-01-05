# Created by: Martin Neubauer <m.ne@gmx.net>
# $FreeBSD$

PORTNAME=	Business-EDI
PORTVERSION=	0.05
CATEGORIES=	misc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JOEATZ
PKGNAMEPREFIX=	p5-
EXTRACT_SUFX=	.tgz

MAINTAINER=	m.ne@gmx.net
COMMENT=	Class for generating EDI objects and subobjects

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Exporter-Easy>=0.14:${PORTSDIR}/devel/p5-Exporter-Easy \
		p5-File-Find-Rule>=0.32:${PORTSDIR}/devel/p5-File-Find-Rule \
		p5-JSON-XS>=2.01:${PORTSDIR}/converters/p5-JSON-XS \
		p5-List-MoreUtils>=0.22:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-UNIVERSAL-require>=0.10:${PORTSDIR}/devel/p5-UNIVERSAL-require
RUN_DEPENDS:=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/atz-${PORTNAME}-327e01f

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
