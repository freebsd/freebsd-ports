# New ports collection makefile for: mailmgr
# Date created:         14 August 2003
# Whom:                 Hsin-Hsiung Chang
#
# $FreeBSD$
#

PORTNAME=	mailmgr
PORTVERSION=	1.2.3
CATEGORIES=	mail
MASTER_SITES=	http://web.onda.com.br/orso/

MAINTAINER=	sexbear@tmu.edu.tw
COMMENT=	Sendmail Analisys Report Generator

GNU_CONFIGURE=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/mailmgr.conf ${PREFIX}/etc/mailmgr.conf.default
.if !exists(${PREFIX}/etc/mailmgr.conf)
	${INSTALL_DATA} ${WRKSRC}/mailmgr.conf ${PREFIX}/etc/mailmgr.conf
.endif
	${INSTALL_PROGRAM} ${WRKSRC}/mailmgr ${PREFIX}/bin
	@${SED} -e 's,PREFIX,${PREFIX},g' ${PKGMESSAGE}

.include <bsd.port.mk>
