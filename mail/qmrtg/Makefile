# New ports collection makefile for:   qmrtg
# Date created:        12 Jun 2004
# Whom:                Mij
#
# $FreeBSD$
#

PORTNAME=	qmrtg
PORTVERSION=	0.5.7
PORTREVISION=	1
CATEGORIES=	mail net-mgmt
MASTER_SITES=	http://dev.publicshout.org/qmrtg/download/

MAINTAINER=	mij@bitchx.it
COMMENT=	A simple tool for monitoring and graphing qmail activity through MRTG

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash2     \
		mrtg:${PORTSDIR}/net-mgmt/mrtg

MAN1=		qmrtg.1
USE_GMAKE=	yes

# this is the local apache documentroot
WWWROOTDIR?=	${PREFIX}/www/data
QMRTG_DBDIR?=	/var/db/${PORTNAME}

PLIST_SUB=	QMRTG_DBDIR=${QMRTG_DBDIR}

post-install:
# in_stall manpages
	@${MKDIR} ${PREFIX}/man/man1
.for foo in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/man/${foo} ${PREFIX}/man/man1
.endfor
.if !defined(WITHOUT_EXAMPLES)
# in_stall conig file examples
	${MKDIR} ${EXAMPLESDIR}
	${CP} ${WRKSRC}/examples/* ${EXAMPLESDIR}/
.endif
.if !defined(WITHOUT_HTMLTEMPLATES)
# in_stall html templates for mrtg graphs
	${MKDIR} ${WWWROOTDIR}/${PORTNAME}
	${CP} ${WRKSRC}/html/* ${WWWROOTDIR}/${PORTNAME}/
.endif
.if !defined(NOPORTDOCS)
# in_stall the few (FAQ, LICENSE etc) files provided by the package
	${MKDIR} ${DOCSDIR}
	${CP} ${WRKSRC}/doc/* ${DOCSDIR}/
.endif
	${MKDIR} ${QMRTG_DBDIR}
	@${CAT} pkg-message

.include <bsd.port.mk>
