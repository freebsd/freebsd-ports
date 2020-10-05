# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	Unix-Processors
PORTVERSION=	2.046
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Interface to processor (CPU) information

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BROKEN_mips=		fails to compile: sys/systeminfo.h: No such file or directory
BROKEN_mips64=		fails to compile: sys/systeminfo.h: No such file or directory

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
