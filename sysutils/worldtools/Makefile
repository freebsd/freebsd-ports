# Created by: anarcat
# $FreeBSD$

PORTNAME=	worldtools
PORTVERSION=	1.3.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://anarcat.ath.cx/software/distfiles/

MAINTAINER=	anarcat@anarcat.ath.cx
COMMENT=	Handy tools for living with make world

USES=		perl5
USE_PERL5=	run

MAN8=		buildit.8 upgrade.8 whereintheworld.8

MAKE_ARGS=	SHAREDIR=${PREFIX}
MANCOMPRESSED=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
