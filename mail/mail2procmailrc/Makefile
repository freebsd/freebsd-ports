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
MASTER_SITES=	http://www.ghettohack.net/timball/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Curses.pm:${PORTSDIR}/devel/p5-Curses \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Curses/Widgets.pm:${PORTSDIR}/devel/p5-Curses-Widgets \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Mail/Header.pm:${PORTSDIR}/mail/p5-Mail-Tools

USE_PERL5=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/generateproc.pl ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/mail2procmail.pl ${PREFIX}/bin/mail2procmail

.include <bsd.port.mk>
