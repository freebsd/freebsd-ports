# New ports collection makefile for:	smtpscan
# Date created:				1 decembre 2002
# Whom:					Hubert Tournier <hubert@frbsd.org>
#
# $FreeBSD$
#

PORTNAME=	smtpscan
PORTVERSION=	0.5
PORTREVISION=	2
CATEGORIES=	security mail perl5
MASTER_SITES=	http://www.frbsd.org/dist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A remote SMTP server version detector

RUN_DEPENDS=	p5-Net-DNS>=0:${PORTSDIR}/dns/p5-Net-DNS

USE_PERL5=	yes
MAN1=	smtpscan.1
MAKEFILE=${FILESDIR}/Makefile
WRKSRC=	${WRKDIR}/${PORTNAME}

.include <bsd.port.mk>
