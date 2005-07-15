# New ports collection makefile for:	qmail-rblchk
# Date created:				21 Jun 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	qmail-rblchk
PORTVERSION=	2.2
CATEGORIES=	mail
MASTER_SITES=	http://morettoni.net/qmail/

MAINTAINER=	ehaupt@critical.ch
COMMENT=	A qmail RBL filter

RUN_DEPENDS=	${QMAIL_DIR}/bin/qmail-send:${PORTSDIR}/mail/qmail

LDFLAGS?=	-s
CFLAGS?=	-O2 -Wimplicit -Wunused -Wcomment -Wchar-subscripts -Wuninitialized \
		-Wshadow -Wcast-qual -Wcast-align -Wwrite-strings

WRKSRC=		${WRKDIR}/${PORTNAME}
QMAIL_DIR?=	/var/qmail

ALL_TARGET=	default
INSTALL_TARGET=	setup

USE_REINPLACE=	yes

PLIST_FILES=	bin/qmail-rblchk %%EXAMPLESDIR%%/spam-report.sh
PLIST_DIRS=	%%EXAMPLESDIR%%
MAN1=		qmail-rblchk.1

post-patch:
	@${REINPLACE_CMD} 's|02755|0755|g; /"cat/d' ${WRKSRC}/hier.c

do-configure:
	${PRINTF}   "${PREFIX}\n\n.../bin.\n"	> ${WRKSRC}/conf-home
	${ECHO_CMD} "${CC} ${CFLAGS}"		> ${WRKSRC}/conf-cc
	${ECHO_CMD} "${CC} ${LDFLAGS}"		> ${WRKSRC}/conf-ld

post-install:
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/spam-report.sh ${EXAMPLESDIR}

.include <bsd.port.mk>
