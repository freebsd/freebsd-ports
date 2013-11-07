# Created by: Sergey Skvortsov <skv@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Pod-Parser
PORTVERSION=	1.61
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Modules to work with POD (Plain Old Documentation)

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure
USE_DOS2UNIX=	yes

post-patch:
	@${REINPLACE_CMD} -e '/EXE_FILES/d' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
