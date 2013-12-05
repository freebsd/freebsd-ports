# Created by: chinsan <chinsan.tw@gmail.com>
# $FreeBSD$

PORTNAME=	ack
PORTVERSION=	2.12
CATEGORIES=	textproc sysutils perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PETDANCE

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Grep-like text finder for large trees of text

LICENSE=	ART20

BUILD_DEPENDS=	p5-File-Next>=0.40:${PORTSDIR}/sysutils/p5-File-Next
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash \
		p5-IO-Tty>=0:${PORTSDIR}/devel/p5-IO-Tty

USES=		perl5
USE_PERL5=	configure

CONFLICTS_INSTALL=	ja-ack-[0-9]*

.include <bsd.port.mk>
