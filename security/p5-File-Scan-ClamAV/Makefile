# Created by: Jan-Peter Koopmann <Jan-Peter.Koopmann@seceidos.de>
# $FreeBSD$

PORTNAME=	File-Scan-ClamAV
PORTVERSION=	1.9.1
PORTREVISION=	3
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for the clamav virus scanner

BUILD_DEPENDS=	clamscan:security/clamav
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
