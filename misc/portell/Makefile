# New ports collection makefile for:   portell
# Date created:        Wed Jan 08 13:25:35 GMT 2003
# Whom:                mich@freebsdcluster.org
#
# $FreeBSD$
#

PORTNAME=	portell
PORTVERSION=	0.1
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	http://freebsdcluster.org/~mich/software/ \
		http://www.seekrut.com/rk/
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	mich@FreeBSD.org
COMMENT=	Quick display of FreeBSD port descriptions

PATCH_WRKSRC=	${WRKDIR}
USE_PYTHON=	YES
USE_REINPLACE=	YES

do-build:
	${REINPLACE_CMD} -e 's/portell.py/portell/' ${WRKDIR}/README

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/portell.py ${PREFIX}/bin/portell
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/README ${DOCSDIR}
.endif

post-install:
.if !defined(BATCH)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "###############################################################################"
	@${ECHO_MSG} "# You must run 'portell -u' to initialize the DB"
	@${ECHO_MSG} "# ${DOCSDIR}/README for more information."
	@${ECHO_MSG} "###############################################################################"
	@${ECHO_MSG} ""
.endif

.include <bsd.port.mk>
