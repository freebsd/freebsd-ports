# ex:ts=8
# Ports collection makefile for:	nanoblogger
# Date created:			Jul 15, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	nanoblogger
PORTVERSION=	2.9
CATEGORIES=	www
MASTER_SITES=	http://home.columbus.rr.com/n1xt3r/downloads/nanoblogger/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small weblog engine for the UNIX command line

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash2

USE_REINPLACE=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/nb etc/nb.conf.default

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

post-patch:
	@${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX}," ${WRKSRC}/nb

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/nb ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/nb.conf ${PREFIX}/etc/nb.conf.default
	@${MKDIR} ${DATADIR}
.for dir in default moods plugins
	${CP} -R ${WRKSRC}/${dir} ${DATADIR}
.endfor
	@${FIND} ${DATADIR} ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${DATADIR} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/nanoblogger.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
