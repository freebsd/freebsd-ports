# New ports collection makefile for:	usendmail
# Date created:		2004-02-19
# Whom:			Thomas Seck <tmseck@netcologne.de>
#
# $FreeBSD$
#
# Tunables: QMAIL_DIR: Where qmail resides (default: /var/qmail)

PORTNAME=	usendmail
PORTVERSION=	0.1.6
CATEGORIES=	mail
MASTER_SITES=	http://www.ohse.de/uwe/usendmail/

MAINTAINER=	tmseck@netcologne.de
COMMENT=	A replacement for qmail's sendmail drop-in

BUILD_DEPENDS=	${QMAIL_DIR}/bin/qmail-send:${PORTSDIR}/mail/qmail
RUN_DEPENDS=	${QMAIL_DIR}/bin/qmail-send:${PORTSDIR}/mail/qmail

QMAIL_DIR?=	/var/qmail

NO_SIZE=	yes
USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/mail/${DISTNAME}

PLIST_FILES=	sbin/usendmail
PORTDOCS=	NEWS README
SUB_FILES=	pkg-message
SUB_LIST=	QMAIL_DIR=${QMAIL_DIR}

post-patch:
	@${REINPLACE_CMD} -e 's,/var/qmail,${QMAIL_DIR},' \
	    ${WRKSRC}/src/usendmail.c
	@${REINPLACE_CMD} -e 's,^CC=,CC\?=,' \
	    ${WRKSRC}/src/Makefile

do-build:
	cd ${WRKSRC} && ./package/build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/command/usendmail ${PREFIX}/sbin/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/src && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
