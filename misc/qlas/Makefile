# New ports collection makefile for:	qlas
# Date created:		14 Oct 2000
# Whom:			Denis Shaposhnikov <dsh@vlink.ru>
#
# $FreeBSD$
#

PORTNAME=	qlas
PORTVERSION=	1.91
CATEGORIES=	misc
MASTER_SITES=	http://lev.serebryakov.spb.ru/download/qlas/

MAINTAINER=	dsh@vlink.ru
COMMENT=	Qico FIDO mailer log analyzer and statistic builder

USE_PERL5=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

post-patch:
	@ ${PERL} -pi -e 's!/usr/bin/perl!${PERL}!; tr/\r//d' ${WRKSRC}/qlas
	@ ${PERL} -pi -e 'tr/\r//d' ${WRKSRC}/qlas.conf.default

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/qlas ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/qlas.conf.default ${PREFIX}/etc/

.include <bsd.port.mk>
