# Created by: Ben Smithurst <ben@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Mail-Sender
PORTVERSION=	0.903
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Module for sending mails with attachments through an SMTP server

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

post-patch:
.if defined(BATCH)
	@${REINPLACE_CMD}  -e 's/res = <STDIN>;/res = "N";/' ${WRKSRC}/Config.PL
.endif

.include <bsd.port.mk>
