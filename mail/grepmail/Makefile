# New ports collection makefile for:	grepmail
# Date created:				20 November 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

PORTNAME=	grepmail
PORTVERSION=	4.80
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	jedgar@FreeBSD.org
COMMENT=	Search mailboxes for a given regexp and display matching emails

BUILD_DEPENDS=	${SITE_PERL}/Date/Parse.pm:${PORTSDIR}/devel/p5-TimeDate
RUN_DEPENDS=	${SITE_PERL}/Date/Parse.pm:${PORTSDIR}/devel/p5-TimeDate

PERL_CONFIGURE=	yes
USE_REINPLACE=	yes

MAN1=		grepmail.1

post-patch:
	@${REINPLACE_CMD} -e 's!<STDIN>!"n"!' ${WRKSRC}/Makefile.PL
	@${REINPLACE_CMD} -e 's|_PERL_|${PERL}|' ${WRKSRC}/grepmail

.include <bsd.port.mk>
