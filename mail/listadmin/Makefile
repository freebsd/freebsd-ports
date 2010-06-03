# New ports collection makefile for: 	listadmin
# Date Created:			29 May 2010
# Whom:					Christer Edwards <christer.edwards@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	listadmin
PORTVERSION=	2.40
CATEGORIES=	mail perl5
MASTER_SITES=	http://heim.ifi.uio.no/kjetilho/hacks/

MAINTAINER=	christer.edwards@gmail.com
COMMENT=	Command-line alternative to Mailman Web interface

RUN_DEPENDS=	${SITE_PERL}/Text/Reform.pm:${PORTSDIR}/textproc/p5-Text-Reform \
		${SITE_PERL}/${PERL_ARCH}/HTML/TokeParser.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${SITE_PERL}/${PERL_ARCH}/Crypt/SSLeay.pm:${PORTSDIR}/security/p5-Crypt-SSLeay \
		${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww

USE_PERL5_RUN=	5.8.0+

PLIST_FILES=	bin/listadmin
MAN1=		listadmin.1

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/listadmin.pl ${PREFIX}/bin/listadmin
	@${INSTALL_MAN} ${WRKSRC}/listadmin.man ${MAN1PREFIX}/man/man1/listadmin.1

.include <bsd.port.mk>
