# Created by: rpsfa@rit.edu
# $FreeBSD$

PORTNAME=	skipfish
PORTVERSION=	2.10b
CATEGORIES=	security www
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	zi@FreeBSD.org
COMMENT=	A fully automated, active web application security reconnaissance tool

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	idn:${PORTSDIR}/dns/libidn \
    		pcre:${PORTSDIR}/devel/pcre

USE_GMAKE=	yes
SUB_FILES=	pkg-message

MAN1=		skipfish.1

.if !defined(NOPORTDOCS)
PORTDOCS=	README COPYING ChangeLog
.endif

NO_STAGE=	yes
.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's:"skipfish.wl":"${DATADIR}/dictionaries/complete.wl":' \
		-e 's:"assets":"${DATADIR}/assets":' ${WRKSRC}/src/config.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/skipfish ${PREFIX}/bin/skipfish
	${INSTALL_SCRIPT} ${WRKSRC}/tools/sfscandiff ${PREFIX}/bin/sfscandiff
	${INSTALL_MAN} ${WRKSRC}/doc/skipfish.1 ${PREFIX}/man/man1
	(cd ${WRKSRC}/assets/ && ${COPYTREE_SHARE} . ${DATADIR}/assets/)
	(cd ${WRKSRC}/dictionaries/ && ${COPYTREE_SHARE} . ${DATADIR}/dictionaries/)
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.	for doc in ${PORTDOCS}
		${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.	endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
