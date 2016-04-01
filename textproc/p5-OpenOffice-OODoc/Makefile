# Created by: meyser@xenet.de
# $FreeBSD$

PORTNAME=	OpenOffice-OODoc
PORTVERSION=	2.125
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	meyser@xenet.de
COMMENT=	Perl Open OpenDocument Connector

LICENSE=	LGPL21

RUN_DEPENDS=	p5-Archive-Zip>=1.18:archivers/p5-Archive-Zip \
		p5-XML-Twig>=3.32:textproc/p5-XML-Twig

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ARGS+=	--noprompt

.include <bsd.port.mk>
