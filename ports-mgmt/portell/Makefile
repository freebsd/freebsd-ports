# New ports collection makefile for:   portell
# Date created:        Wed Jan 08 13:25:35 GMT 2003
# Whom:                mich@freebsdcluster.org
#
# $FreeBSD$
#

PORTNAME=	portell
PORTVERSION=	0.1
CATEGORIES=	misc
MASTER_SITES=	http://www.seekrut.com/rk/
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	mich@freebsdcluster.org

USE_PYTHON=	YES
NO_BUILD=	YES

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.py ${PREFIX}/bin

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/README ${DOCSDIR}
.endif

post-install:
.if !defined(BATCH)
	@${ECHO_CMD} ""
	@${ECHO_CMD} "###############################################################################"
	@${ECHO_CMD} "# You must run 'portell.py -u' to initialize the DB.                          #"
	@${ECHO_CMD} "# ${DOCSDIR}/README for more information.                                     #"
	@${ECHO_CMD} "###############################################################################"
	@${ECHO_CMD}
.endif

.include <bsd.port.mk>
