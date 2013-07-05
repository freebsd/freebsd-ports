# Created by: petef
# $FreeBSD$

PORTNAME=	qmhandle
PORTVERSION=	1.3.2
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-1.3/${PORTNAME}-${PORTVERSION}

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	Tool to view and manage a qmail queue

LICENSE=	GPLv2

OPTIONS_DEFINE=	DOCS

USES=		qmail:run

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
