# Created by: Yonatan <onatan@gmail.com>
# $FreeBSD$

PORTNAME=	hmap
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://ujeni.murkyroc.com/hmap/code/current/
DISTNAME=	${PORTNAME}

MAINTAINER=	onatan@gmail.com
COMMENT=	Web server fingerprinting utility

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/GPL

USE_DOS2UNIX=	yes
USE_PYTHON=	yes

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} -e 's|DATADIR|${DATADIR}|' ${WRKSRC}/hmap.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/hmap.py ${PREFIX}/bin/
	${MKDIR} ${DATADIR}
	(cd ${WRKSRC}/known.servers/ && ${COPYTREE_SHARE} \* ${DATADIR})
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in README BUGS FAQS HIDING_GUIDE KNOWN_TESTS
	${INSTALL_DATA} ${WRKSRC}/$i ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
