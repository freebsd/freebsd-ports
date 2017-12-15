# Created by: Thomas Seck <tmseck@netcologne.de>
# $FreeBSD$

PORTNAME=	usendmail
PORTVERSION=	0.1.6
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://www.ohse.de/uwe/usendmail/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Replacement for qmail's sendmail drop-in

USES=		qmail

BROKEN_aarch64=		fails to build: regparm is not valid on this platform
BROKEN_armv6=		fails to build: regparm is not valid on this platform
BROKEN_armv7=		fails to build: auto-aliastest.c:3:34: error: alias must point to a defined variable or function

WRKSRC=		${WRKDIR}/mail/${DISTNAME}

PLIST_FILES=	sbin/usendmail
PORTDOCS=	NEWS README
SUB_FILES=	pkg-message
SUB_LIST=	QMAIL_PREFIX=${QMAIL_PREFIX}

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's,/var/qmail,${QMAIL_PREFIX},' \
		${WRKSRC}/src/usendmail.c
	@${REINPLACE_CMD} -e 's,^CC=,CC\?=,' \
		${WRKSRC}/src/Makefile

do-test:
	cd ${WRKSRC} && ./package/check

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/command/usendmail ${STAGEDIR}${PREFIX}/sbin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/src && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
