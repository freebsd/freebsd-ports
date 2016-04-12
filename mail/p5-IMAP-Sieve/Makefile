# Created by: Oliver Eikemeier <eikemeier@fillmore-labs.com>
# $FreeBSD$

PORTNAME=	IMAP-Sieve
PORTVERSION=	0.4.9
PORTREVISION=	3
CATEGORIES=	mail perl5
MASTER_SITES=	SF/websieve/websieve/063a
PKGNAMEPREFIX=	p5-
DISTNAME=	websieve-063a

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl module to edit Sieve scripts on an Cyrus IMAP server

RUN_DEPENDS=	p5-IO-Socket-SSL>=0:security/p5-IO-Socket-SSL

WRKSRC=		${WRKDIR}/${PERLSIEVENAME}

USES=		perl5
USE_PERL5=	configure

PERLSIEVENAME=	perlsieve-${PORTVERSION}
PERLSIEVESUFX=	b

post-extract:
	@${TAR} ${EXTRACT_BEFORE_ARGS} \
		${WRKDIR}/${DISTNAME}/${PERLSIEVENAME}${PERLSIEVESUFX}${EXTRACT_SUFX} \
			${EXTRACT_AFTER_ARGS} -C ${WRKDIR}
	@${RM} ${WRKSRC}/testssl.pl

.include <bsd.port.mk>
