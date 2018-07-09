# $FreeBSD$

PORTNAME=	Clamd
PORTVERSION=	1.04
PORTREVISION=	4
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MSERGEANT
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Clamd - Connect to a local clamd service and send commands

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	clamd:security/clamav

USES=		perl5
USE_PERL5=	configure

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
