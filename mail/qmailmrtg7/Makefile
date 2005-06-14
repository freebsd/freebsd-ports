# New ports collection makefile for:	qmailmrtg7
# Date created:			16 Jun 2004
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	qmailmrtg7
PORTVERSION=	4.2
CATEGORIES=	mail net-mgmt
MASTER_SITES=	http://www.inter7.com/qmailmrtg7/

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A program to create mrtg graphs for qmail activity

BUILD_DEPENDS=	${QMAIL_DIR}/bin/qmail-queue:${PORTSDIR}/mail/qmail
RUN_DEPENDS=	${QMAIL_DIR}/bin/qmail-queue:${PORTSDIR}/mail/qmail \
		mrtg:${PORTSDIR}/net-mgmt/mrtg

USE_REINPLACE=	yes

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/qmail/bin/qmail-queue)
QMAIL_DIR?=	${LOCALBASE}/qmail
.else
QMAIL_DIR?=	/var/qmail
.endif

post-patch:
	@${REINPLACE_CMD} "s|cc|${CC}|g;s|-s -O|${CFLAGS}|g" ${WRKSRC}/Makefile
	@${REINPLACE_CMD} "s|/usr/local|${PREFIX}|g;s|/var/qmail|${QMAIL_DIR}|g" \
		${WRKSRC}/checkq.c ${WRKSRC}/qmail.mrtg.cfg

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qmailmrtg7 ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/qmail.mrtg.cfg ${PREFIX}/etc/qmail.mrtg.cfg.sample
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/index.html ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/FAQ ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
