# New ports collection makefile for:	smtpscan
# Date created:				1 decembre 2002
# Whom:					Hubert Tournier <hubert@frbsd.org>
#
# $FreeBSD$
#

PORTNAME=	smtpscan
PORTVERSION=	0.5
CATEGORIES=	security mail perl5
MASTER_SITES=	http://www.greyhats.org/outils/smtpscan/

MAINTAINER=	hubert@frbsd.org
COMMENT=	A remote SMTP server version detector

RUN_DEPENDS=	${SITE_PERL}/Getopt/Long.pm:${PORTSDIR}/devel/p5-Getopt-Long \
		${SITE_PERL}/${PERL_ARCH}/IO.pm:${PORTSDIR}/devel/p5-IO \
		${SITE_PERL}/Net/DNS.pm:${PORTSDIR}/dns/p5-Net-DNS

USE_PERL5=	yes
MAN1=		smtpscan.1
WRKSRC=		${WRKDIR}/${PORTNAME}

pre-build:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}/Makefile

.include <bsd.port.mk>
