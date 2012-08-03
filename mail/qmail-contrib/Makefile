# New ports collection makefile for:	qmail-contrib
# Date created:		28 November 1998
# Whom:			Neil Blakey-Milner <nbm@rucus.ru.ac.za>
#
# $FreeBSD$
#

PORTNAME=	qmail-contrib
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://cr.yp.to/software/ \
		${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles
DISTFILES=	dot-forward-${DF_VER}.tar.gz \
		fastforward-${FF_VER}.tar.gz

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Contributed programs for qmail

OPTIONS_DEFINE=	DOCS
OPTIONS_DEFAULT=DOCS

USE_QMAIL_RUN=	yes
MAKE_JOBS_SAFE=	yes

ALL_TARGET=	it
INSTALL_TARGET=	setup

MAN1=		dot-forward.1 fastforward.1 printforward.1 setforward.1 \
		newaliases.1 printmaillist.1 setmaillist.1 newinclude.1

PREFIX?=	${QMAIL_PREFIX}

FF_VER=		0.51
DF_VER=		0.71
QCK_VER=	0.1

WRKFF=		${WRKDIR}/fastforward-${FF_VER}
WRKDF=		${WRKDIR}/dot-forward-${DF_VER}

NO_MTREE=	yes

PORTDOCS=	ALIASES

.include <bsd.port.pre.mk>

.if (${PREFIX} != ${LOCALBASE})
DOCSDIR=	doc
.endif

pre-patch:
	@${PATCH} -d ${WRKFF} -s <${PATCHDIR}/extra-patch-newaliases

post-patch:
	@${REINPLACE_CMD} -e "s|.var.qmail|${QMAIL_PREFIX}|" \
		${WRKFF}/conf-qmail \
		${WRKDF}/conf-qmail
	@${REINPLACE_CMD} -e '/cat/d; s|doc/fastforward|${DOCSDIR}|g' \
		${WRKFF}/hier.c \
		${WRKDF}/hier.c
	@${REINPLACE_CMD} -e "s|-O2|${CFLAGS}|" \
		${WRKFF}/conf-cc \
		${WRKDF}/conf-cc
.if empty(PORT_OPTIONS:MDOCS)
	@${REINPLACE_CMD} -E 's|^(.*${DOCSDIR})|// \1|g' \
		${WRKFF}/hier.c
.endif

do-build:
	@${MAKE} -C ${WRKDIR}/dot-forward-${DF_VER} ${ALL_TARGET}
	@${MAKE} -C ${WRKDIR}/fastforward-${FF_VER} ${ALL_TARGET}

do-install:
	@${MAKE} -C ${WRKDIR}/dot-forward-${DF_VER} ${INSTALL_TARGET}
	@${MAKE} -C ${WRKDIR}/fastforward-${FF_VER} ${INSTALL_TARGET}

.include <bsd.port.post.mk>
