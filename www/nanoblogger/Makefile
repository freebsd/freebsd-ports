# ex:ts=8
# Ports collection makefile for:	nanoblogger
# Date created:			Jul 15, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	nanoblogger
PORTVERSION=	3.3
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small weblog engine written in Bash for the command line

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

NO_BUILD=	yes

SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX},g" ${WRKSRC}/nb

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/nb ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/nb.conf ${PREFIX}/etc/nb.conf.sample
	${MKDIR} ${DATADIR}
.for data in default lang lib moods plugins
	${CP} -R ${WRKSRC}/${data} ${DATADIR}
.endfor
	${CP} ${WRKSRC}/welcome-to-nb.txt ${DATADIR}

post-install:
	@if [ ! -f ${PREFIX}/etc/nb.conf ]; then \
		${CP} -p ${PREFIX}/etc/nb.conf.sample ${PREFIX}/etc/nb.conf; \
	fi
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for doc in COPYING ChangeLog README TODO docs/nanoblogger.html
	${INSTALL_MAN} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
