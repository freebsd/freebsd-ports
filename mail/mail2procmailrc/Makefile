# Created by: ijliao
# $FreeBSD$

PORTNAME=	mail2procmailrc
PORTVERSION=	0.9
CATEGORIES=	mail
MASTER_SITES=	http://www.tux.org/~timball/download/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	mail to procmailrc generator

RUN_DEPENDS=	p5-Curses>=0:${PORTSDIR}/devel/p5-Curses \
		p5-Curses-Widgets>=0:${PORTSDIR}/devel/p5-Curses-Widgets \
		p5-Mail-Tools>=0:${PORTSDIR}/mail/p5-Mail-Tools

DEPRECATED=	Unmaintained since 2001
EXPIRATION_DATE=	2014-04-12
USES=		perl5
NO_BUILD=	yes

NO_STAGE=	yes
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/generateproc.pl ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/mail2procmail.pl ${PREFIX}/bin/mail2procmail

.include <bsd.port.mk>
