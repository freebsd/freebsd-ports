# New ports collection makefile for:	qmHandle
# Date created:				17 August 2001
# Whom:					petef
#
# $FreeBSD$
#

PORTNAME=	qmhandle
PORTVERSION=	1.3.2
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-1.3/${PORTNAME}-${PORTVERSION}

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Tool to view and manage a qmail queue

OPTIONS_DEFINE=	DOCS
OPTIONS_DEFAULT=DOCS

USE_QMAIL_RUN=	yes

NO_BUILD=	yes
USE_PERL5=	yes
USE_BZIP2=	yes

PORTDOCS=	HISTORY README

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,^#!/usr/bin/perl,#!${PERL},g' \
			  -e 's,%%LOCALBASE%%,${LOCALBASE},g' \
			  -e '/^##* *USER *CONFIGURATION *BEGIN *##*$$/,/^##* *USER *CONFIGURATION *END *##*$$/s/^\(#*\)my/\1our/g' \
		${WRKSRC}/qmHandle
	@${SED} -e 's,%%LOCALBASE%%,${LOCALBASE},g' ${FILESDIR}/qmHandle.conf.in > \
		${WRKSRC}/qmHandle.conf.sample

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/qmHandle ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/qmHandle.conf.sample ${PREFIX}/etc
	[ -f ${PREFIX}/etc/qmHandle.conf ] || \
		${INSTALL_DATA} -m 0644 ${WRKSRC}/qmHandle.conf.sample ${PREFIX}/etc/qmHandle.conf
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
