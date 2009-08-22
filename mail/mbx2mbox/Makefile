# New ports collection makefile for:	mbx2mbox
# Date created:		23 November 1998
# Whom:			Josh Gilliam <josh@quick.net>
#
# $FreeBSD$
#

PORTNAME=	mbx2mbox
PORTVERSION=	0.34
CATEGORIES=	mail
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MS Outlook Express .mbx to mbox file converter

BUILD_DEPENDS=	${SITE_PERL}/Date/Manip.pm:${PORTSDIR}/devel/p5-Date-Manip
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=	mbx2mbox.1

.include <bsd.port.mk>
