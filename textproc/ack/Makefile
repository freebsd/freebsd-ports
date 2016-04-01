# Created by: chinsan <chinsan.tw@gmail.com>
# $FreeBSD$

PORTNAME=	ack
PORTVERSION=	2.14
PORTREVISION=	1
CATEGORIES=	textproc sysutils perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PETDANCE

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Grep-like text finder for large trees of text

LICENSE=	ART20

BUILD_DEPENDS=	p5-File-Next>=0.40:sysutils/p5-File-Next
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	bash:shells/bash \
		p5-IO-Tty>=0:devel/p5-IO-Tty

CONFLICTS_INSTALL=	ja-ack-[0-9]*

PORTSCOUT=	limit:^[0-9\.]*$$

USES=		cpe perl5
USE_PERL5=	configure
CPE_VENDOR=	beyondgrep

.include <bsd.port.mk>
