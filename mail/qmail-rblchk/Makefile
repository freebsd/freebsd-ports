# New ports collection makefile for:	qmail-rblchk
# Date created:				21 Jun 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	qmail-rblchk
PORTVERSION=	2.4.1
CATEGORIES=	mail
MASTER_SITES=	http://morettoni.net/qmail/

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A qmail RBL filter

USE_QMAIL_RUN=	yes

LDFLAGS?=	-s
CFLAGS?=	-O2 -Wimplicit -Wunused -Wcomment -Wchar-subscripts -Wuninitialized \
		-Wshadow -Wcast-qual -Wcast-align -Wwrite-strings

WRKSRC=		${WRKDIR}/${PORTNAME}

ALL_TARGET=	default
INSTALL_TARGET=	setup

PLIST_FILES=	bin/qmail-rblchk bin/getsenderip \
		%%EXAMPLESDIR%%/spam-report.sh %%EXAMPLESDIR%%/rbllist.sh \
		%%EXAMPLESDIR%%/dot-qmail-storeip
PLIST_DIRS=	%%EXAMPLESDIR%%
MAN1=		qmail-rblchk.1 getsenderip.1

post-patch:
	@${REINPLACE_CMD} -e '/"cat/d; s|,02755|,0755|' ${WRKSRC}/hier.c

do-configure:
	${PRINTF}   "${PREFIX}\n\n.../bin.\n"	> ${WRKSRC}/conf-home
	${ECHO_CMD} "${CC} ${CFLAGS}"		> ${WRKSRC}/conf-cc
	${ECHO_CMD} "${CC} ${LDFLAGS}"		> ${WRKSRC}/conf-ld

post-install:
	${MKDIR} ${EXAMPLESDIR}
.for f in rbllist.sh spam-report.sh dot-qmail-storeip
	${INSTALL_DATA} ${WRKSRC}/contrib/${f} ${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
