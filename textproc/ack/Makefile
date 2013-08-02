# Created by: chinsan <chinsan.tw@gmail.com>
# $FreeBSD$

PORTNAME=	ack
PORTVERSION=	2.04
CATEGORIES=	textproc perl5 sysutils
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	App

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Grep-like text finder for large trees of text

BUILD_DEPENDS=	p5-File-Next>=0.40:${PORTSDIR}/sysutils/p5-File-Next
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

CONFLICTS_INSTALL=	ja-ack-[0-9]*

MAN1=		ack.1

.include <bsd.port.mk>
