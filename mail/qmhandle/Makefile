# Created by: petef
# $FreeBSD$

PORTNAME=	qmhandle
PORTVERSION=	1.3.2
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-1.3/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to view and manage a qmail queue

LICENSE=	GPLv2

OPTIONS_DEFINE=	DOCS

USES=		qmail:run perl5 tar:bzip2

NO_BUILD=	yes

PORTDOCS=	HISTORY README

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,^#!/usr/bin/perl,#!${PERL},g' \
			  -e 's,%%LOCALBASE%%,${LOCALBASE},g' \
			  -e '/^##* *USER *CONFIGURATION *BEGIN *##*$$/,/^##* *USER *CONFIGURATION *END *##*$$/s/^\(#*\)my/\1our/g' \
		${WRKSRC}/qmHandle
	@${SED} -e 's,%%LOCALBASE%%,${LOCALBASE},g' ${FILESDIR}/qmHandle.conf.in > \
		${WRKSRC}/qmHandle.conf.sample

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/qmHandle ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/qmHandle.conf.sample ${STAGEDIR}${PREFIX}/etc
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
