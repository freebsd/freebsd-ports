# ex:ts=8
# New ports collection makefile for:	mail2procmailrc
# Date created:			Dec 29, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	mail2procmailrc
PORTVERSION=	0.9
CATEGORIES=	mail
MASTER_SITES=	http://www.tux.org/~timball/download/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	mail to procmailrc generator

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Curses.pm:${PORTSDIR}/devel/p5-Curses \
		${SITE_PERL}/Curses/Widgets.pm:${PORTSDIR}/devel/p5-Curses-Widgets \
		${SITE_PERL}/Mail/Header.pm:${PORTSDIR}/mail/p5-Mail-Tools

USE_PERL5=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/generateproc.pl ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/mail2procmail.pl ${PREFIX}/bin/mail2procmail

.include <bsd.port.mk>
