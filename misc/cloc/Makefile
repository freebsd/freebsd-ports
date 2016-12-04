# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cloc
PORTVERSION=	1.70
DISTVERSIONPREFIX=	v
CATEGORIES=	misc
EXTRACT_SUFX=	.pl

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Counts lines of code

LICENSE=	GPLv2

RUN_DEPENDS=	p5-Algorithm-Diff>=0:devel/p5-Algorithm-Diff

USE_GITHUB=	yes
GH_ACCOUNT=	AlDanial
GH_PROJECT=	${PORTNAME}

USES=		perl5
USE_PERL5=	run
PLIST_FILES=	bin/${PORTNAME}
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
