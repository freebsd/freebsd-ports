# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	XML-SAX
PORTVERSION=	1.00
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple API for XML

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-XML-NamespaceSupport>=0.03:textproc/p5-XML-NamespaceSupport \
		p5-XML-SAX-Base>=1.05:textproc/p5-XML-SAX-Base

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

PKGDEINSTALL=	${PKGINSTALL}
SUB_FILES=	pkg-install
SUB_LIST=	PERL=${PERL}

.include <bsd.port.mk>
