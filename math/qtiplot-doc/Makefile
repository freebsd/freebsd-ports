# New ports collection makefile for:	qtiplot-doc
# Date created:		2006-09-08
# Whom:			Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	qtiplot-doc
PORTVERSION=	0.8.9
CATEGORIES=	math
MASTER_SITES=	http://soft.proindependent.com/doc/
DISTNAME=	manual-en

MAINTAINER=	makc@issp.ac.ru
COMMENT=	The QtiPlot Handbook

USE_BZIP2=	yes
NO_BUILD=	yes
DATADIR=	${PREFIX}/share/qtiplot/manual

PLIST=		${WRKDIR}/pkg-plist

.include <bsd.port.pre.mk>

pre-install:
	@${ECHO_CMD} '@exec mkdir -p %D/share/qtiplot/manual' > ${PLIST}
	@${FIND} ${WRKSRC} -type f | \
		${SED} -e "s:^${WRKSRC}/:share/qtiplot/manual/:g" >> ${PLIST}
	@${FIND} -d ${WRKSRC} -type d | \
		${SED} -e "s:^${WRKSRC}:@dirrm share/qtiplot/manual:g" >> ${PLIST}
	@${ECHO_CMD} "@dirrmtry share/qtiplot" >> ${PLIST}

do-install:
	@${MKDIR} ${DATADIR}
	${TAR} -C ${WRKSRC} --exclude CVS -cf - . | \
		${TAR} -C ${DATADIR} --unlink -xf -

.include <bsd.port.post.mk>
