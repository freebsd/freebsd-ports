# New ports collection makefile for:	synonym
# Date created:				2005/11/16
# Whom:					Norikatsu Shigemura <n-shigemura@ensure.jp>
#
# $FreeBSD$
#

PORTNAME=	synonym
PORTVERSION=	0.4.3
CATEGORIES=	mail security
MASTER_SITES=	http://www.dv8.ro/Synonym/Synonym/source/
DISTNAME=	${PORTNAME}-0.4-3

MAINTAINER=	nork@FreeBSD.org
COMMENT=	Synonym, the email message archiver

USE_GMAKE=	yes
USE_GNOME=	libxml2

WRKSRC=		${WRKDIR}/${PORTNAME}-0.4
PORTDOCS=	README license.txt
USE_RC_SUBR=	synonym

MAKE_ENV+=	PTHREAD_CFLAGS=${PTHREAD_CFLAGS} \
		PTHREAD_LIBS=${PTHREAD_LIBS} \
		DOCSDIR=${DOCSDIR} \
		RUNDIR=${RUNDIR} \
		SYNONYMOWN=${SYNONYMOWN} SYNONYMGRP=${SYNONYMGRP}
PLIST_SUB+=	RUNDIR=${RUNDIR}
SUB_LIST+=	RUNDIR=${RUNDIR}
SUB_FILES=	pkg-message

RUNDIR?=	/var/run/synonym
SYNONYMOWN?=	daemon
SYNONYMGRP?=	daemon

PKGMESSAGE=	${WRKDIR}/pkg-message

post-extract:
		@${RM} ${WRKSRC}/*.o

.include <bsd.port.pre.mk>

do-install:
		@${INSTALL_PROGRAM} ${WRKSRC}/synonym      ${PREFIX}/sbin/
		@${INSTALL_DATA}    ${WRKSRC}/synonym.conf ${PREFIX}/etc/synonym.conf-dist
		@[ -f ${PREFIX}/etc/synonym.conf ] || \
		 ${INSTALL_DATA}    ${WRKSRC}/synonym.conf ${PREFIX}/etc/synonym.conf
.if !defined(NOPORTDOCS)
		@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
		@${INSTALL_DATA}    ${WRKSRC}/${f} ${DOCSDIR}/${f}
.endfor
.endif
		@${MKDIR} ${RUNDIR}
		@${CHOWN} ${SYNONYMOWN}:${SYNONYMGRP} ${RUNDIR}
		@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
