# Created by: mich@freebsdcluster.org
# $FreeBSD$

PORTNAME=	portell
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://www.freebsdcluster.org/~mich/software/

MAINTAINER=	mich@FreeBSD.org
COMMENT=	Quick display of FreeBSD port descriptions

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bsddb>0:databases/py-bsddb

USES=		python zip
NO_BUILD=	yes

PLIST_FILES=	bin/portell
PORTDOCS=	README.txt

post-extract:
	${REINPLACE_CMD} -e 's/[[:cntrl:]]*$$//' ${WRKSRC}/portell.py
	${REINPLACE_CMD} -e 's/free/freebsd/' ${WRKSRC}/portell.py
	${REINPLACE_CMD} -e 's/portell.py/portell/' ${WRKSRC}/README.txt

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/portell.py ${STAGEDIR}${PREFIX}/bin/portell
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${STAGEDIR}${DOCSDIR}

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
