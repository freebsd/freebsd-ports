# New ports collection makefile for:	p5-IMAP-Sieve
# Date created:				25 Apr 2003
# Whom:				Oliver Eikemeier <eikemeier@fillmore-labs.com>
#
# $FreeBSD$
#

PORTNAME=	IMAP-Sieve
PORTVERSION=	0.4.9
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	websieve
PKGNAMEPREFIX=	p5-
DISTNAME=	websieve-0.61

MAINTAINER=	eik@FreeBSD.org
COMMENT=	Perl module to edit Sieve scripts on an Cyrus IMAP server

RUN_DEPENDS=	${SITE_PERL}/IO/Socket/SSL.pm:${PORTSDIR}/security/p5-IO-Socket-SSL \
		${SITE_PERL}/${PERL_ARCH}/IO.pm:${PORTSDIR}/devel/p5-IO

WRKSRC=		${WRKDIR}/${PERLSIEVENAME}

PERL_CONFIGURE=	yes

PERLSIEVENAME=	perlsieve-${PORTVERSION}
PERLSIEVESUFX=	b

post-extract:
	@${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		${WRKDIR}/websieve/${PERLSIEVENAME}${PERLSIEVESUFX}${EXTRACT_SUFX} \
			${EXTRACT_AFTER_ARGS} -C ${WRKDIR}
	@${RM} ${WRKSRC}/testssl.pl

.include <bsd.port.mk>
