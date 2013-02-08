# Created by: Neil Blakey-Milner <nbm@rucus.ru.ac.za>
# $FreeBSD$

PORTNAME=	qmailanalog
PORTVERSION=	0.70
PORTREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	http://cr.yp.to/software/ \
		http://www.emaillab.org/djb/qmailanalog/

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	Tools to analyze qmail-send's activity

USE_QMAIL_RUN=	yes
MAKE_JOBS_SAFE=	yes

ALL_TARGET=	it
INSTALL_TARGET=	setup

MANPREFIX=	${QMPREFIX}
MAN1=		matchup.1 xqp.1 xsender.1 xrecipient.1 columnt.1

PLIST_SUB+=	MYSUBDIR=${MYSUBDIR}

.if !defined(NOSUBDIR)
MYSUBDIR?=	qmailanalog/
.else
MYSUBDIR?=
.endif

PREFIX?=	${QMAIL_PREFIX}
QMPREFIX?=	${PREFIX}/${MYSUBDIR}

NO_MTREE=	yes

.include <bsd.port.pre.mk>

.if ${PREFIX} != ${QMAIL_PREFIX}
BROKEN=	Cannot Make and Install with different PREFIX or QMAIL_PREFIX
.endif

post-patch:
	@${REINPLACE_CMD} "s|.usr.local.qmailanalog|${QMPREFIX}|" ${WRKSRC}/conf-home
	@${REINPLACE_CMD} "s|-O2|${CFLAGS}|" ${WRKSRC}/conf-cc
	@${REINPLACE_CMD} 's|02755|0755|g; /cat/d' ${WRKSRC}/hier.c
	@${REINPLACE_CMD} 's|^man prog|prog|g' ${WRKSRC}/Makefile

pre-install:
	@${MKDIR} ${QMPREFIX}

.include <bsd.port.post.mk>
