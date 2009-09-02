# New ports collection makefile for:	p5-IMAP-Sieve
# Date created:				25 Apr 2003
# Whom:				Oliver Eikemeier <eikemeier@fillmore-labs.com>
#
# $FreeBSD$
#

PORTNAME=	IMAP-Sieve
PORTVERSION=	0.4.9
PORTREVISION=	2
CATEGORIES=	mail perl5
MASTER_SITES=	SF/websieve/websieve/063a
PKGNAMEPREFIX=	p5-
DISTNAME=	websieve-063a

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl module to edit Sieve scripts on an Cyrus IMAP server

RUN_DEPENDS=	${SITE_PERL}/IO/Socket/SSL.pm:${PORTSDIR}/security/p5-IO-Socket-SSL

WRKSRC=		${WRKDIR}/${PERLSIEVENAME}

PERL_CONFIGURE=	yes

PERLSIEVENAME=	perlsieve-${PORTVERSION}
PERLSIEVESUFX=	b

post-extract:
	@${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		${WRKDIR}/${DISTNAME}/${PERLSIEVENAME}${PERLSIEVESUFX}${EXTRACT_SUFX} \
			${EXTRACT_AFTER_ARGS} -C ${WRKDIR}
	@${RM} ${WRKSRC}/testssl.pl

.include <bsd.port.mk>
