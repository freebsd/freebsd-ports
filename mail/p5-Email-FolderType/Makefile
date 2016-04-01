# Created by: Lars Thegler <lars@thegler.dk>
# $FreeBSD$

PORTNAME=	Email-FolderType
PORTVERSION=	0.8.14
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-0.814

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Determine the type of a mail folder

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

TEST_DEPENDS=	p5-Capture-Tiny>0:devel/p5-Capture-Tiny

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} >= 502000
BUILD_DEPENDS+=	p5-Module-Pluggable>0:devel/p5-Module-Pluggable
RUN_DEPENDS+=	p5-Module-Pluggable>0:devel/p5-Module-Pluggable
.endif

.include <bsd.port.post.mk>
