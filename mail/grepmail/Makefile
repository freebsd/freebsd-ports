# New ports collection makefile for:	grepmail
# Date created:				20 November 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

PORTNAME=	grepmail
PORTVERSION=	5.30
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	jedgar@FreeBSD.org
COMMENT=	Search mailboxes for a given regexp and display matching emails

BUILD_DEPENDS=	${SITE_PERL}/Date/Parse.pm:${PORTSDIR}/devel/p5-TimeDate \
		${SITE_PERL}/Mail/Mbox/MessageParser.pm:${PORTSDIR}/mail/p5-Mail-Mbox-MessageParser
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		grepmail.1

.include <bsd.port.mk>
