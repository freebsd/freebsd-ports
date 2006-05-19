# New ports collection makefile for:    denyhosts
# Date created:         		04 November 2005
# Whom:                 		Janos Mohacsi <janos.mohacsi@bsd.hu>
#
# $FreeBSD$
#

PORTNAME=	denyhosts
DISTVERSION=	2.4b
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	DenyHosts-${DISTVERSION}

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Script to thwart ssh attacks

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

USE_RC_SUBR=	denyhosts

DOC_FILES=	CHANGELOG.txt LICENSE.txt README.txt

pre-configure:
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' \
		${WRKSRC}/daemon-control-dist \
		${WRKSRC}/denyhosts.cfg-dist \
		${WRKSRC}/setup.py

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
