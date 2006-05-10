# New ports collection makefile for:   portell
# Date created:        Wed Jan 08 13:25:35 GMT 2003
# Whom:                mich@freebsdcluster.org
#
# $FreeBSD$
#

PORTNAME=	portell
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.zip

MAINTAINER=	mich@FreeBSD.org
COMMENT=	Quick display of FreeBSD port descriptions

USE_ZIP=	YES
USE_PYTHON=	YES
NO_BUILD=	YES

PLIST_FILES=	bin/portell
PORTDOCS=	README.txt

post-extract:
	${REINPLACE_CMD} -e 's/[[:cntrl:]]*$$//' ${WRKSRC}/portell.py
	${REINPLACE_CMD} -e 's/free/freebsd/' ${WRKSRC}/portell.py
	${REINPLACE_CMD} -e 's/portell.py/portell/' ${WRKSRC}/README.txt

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/portell.py ${PREFIX}/bin/portell
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DOCSDIR}
.endif

post-install:
.if !defined(BATCH)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "###############################################################################"
	@${ECHO_MSG} "# You must run 'portell -u' to initialize the DB"
	@${ECHO_MSG} "# ${DOCSDIR}/README.txt for more information."
	@${ECHO_MSG} "###############################################################################"
	@${ECHO_MSG} ""
.endif

.include <bsd.port.mk>
