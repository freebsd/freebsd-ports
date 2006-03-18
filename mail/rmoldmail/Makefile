# New ports collection makefile for:	rmoldmail
# Date created:				7 June 2001
# Whom:					petef@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	rmoldmail
PORTVERSION=	0.1.0
CATEGORIES=	mail
MASTER_SITES=	#

MAINTAINER=	petef@FreeBSD.org
COMMENT=	Prune a mailbox of messages older than a set number of days

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Date/Calc.pm:${PORTSDIR}/devel/p5-Date-Calc

DEPRECATED=	mastersite disappeared, no longer maintained by author
EXPIRATION_DATE=	2006-04-07

NO_BUILD=	yes

USE_PERL5=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rmoldmail.RUNconfigure.pl \
		${PREFIX}/sbin/rmoldmail
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/rmoldmail
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/rmoldmail
.endif

.include <bsd.port.mk>
