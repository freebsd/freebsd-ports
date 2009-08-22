# ports collection makefile for:	pm-lib
# Date created:				14 November 2001
# Whom:					Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	pm-lib
PORTVERSION=	20041216
CATEGORIES=	mail
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/2004.1216
DISTNAME=	procmail-lib-2004.1216

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A collection of procmail plug-in modules

RUN_DEPENDS=	procmail:${PORTSDIR}/mail/procmail

NO_BUILD=	yes

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

.include <bsd.port.pre.mk>

do-install:
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/lib/pm-*.rc ${DATADIR}
	@${FIND} ${DATADIR} -type f | \
		${SED} -e 's,${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${DATADIR} -type d | ${SORT} -r | \
		${SED} -e 's,${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/lib/ChangeLog ${DOCSDIR}
.for i in README.txt pm-lib.txt
	${INSTALL_DATA} ${WRKSRC}/doc/source/${i} ${DOCSDIR}
.endfor
	@${MKDIR} ${DOCSDIR}/html
	${CP} -R ${WRKSRC}/doc/html/ ${DOCSDIR}/html
.endif

.include <bsd.port.post.mk>
