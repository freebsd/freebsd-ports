# New ports collection makefile for:	Yorick-doc
# Date created:         25 Jan 02
# Whom:                 David H. Munro <munro1@llnl.gov>
#
# $FreeBSD$
#

PORTNAME=	yorick-doc
PORTVERSION=	1.6.02
CATEGORIES=	lang math
MASTER_SITES=	ftp://ftp-icf.llnl.gov/pub/Yorick/ \
		ftp://wuarchive.wustl.edu/languages/yorick/
DISTNAME=	yorick-${PORTVERSION:R}-${PORTVERSION:E}-doc
EXTRACT_SUFX=	.tgz

MAINTAINER=	johans@stack.nl
COMMENT=	Yorick interpreted language full documentation

WRKSRC=		${WRKDIR}/yorick-${PORTVERSION:R}-${PORTVERSION:E}/doc
DOCSDIR=	${PREFIX}/share/doc/yorick

NO_BUILD=	true
PLIST=		${WRKDIR}/pkg-plist

pre-install:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} | ${SED} -e 's|^|%%DOCSDIR%%/|' >> ${PLIST} && \
	${FIND} * -type d ! -empty | ${SORT} -r | ${SED} -e 's|^|@dirrm %%DOCSDIR%%/|' >> ${PLIST}
	@${ECHO_CMD} '@dirrm %%DOCSDIR%%' >> ${PLIST}

do-install:
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && \
	${FIND} * -type d ! -empty -exec ${MKDIR} "${DOCSDIR}/{}" \; && \
	${FIND} * ! -type d -exec ${INSTALL_DATA} "{}" "${DOCSDIR}/{}" \;

.include <bsd.port.mk>
