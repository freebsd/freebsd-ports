# New ports collection makefile for:    denyhosts
# Date created:         		04 November 2005
# Whom:                 		Janos Mohacsi <janos.mohacsi@bsd.hu>
#
# $FreeBSD$
#

PORTNAME=	denyhosts
PORTVERSION=	2.6
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	SF
DISTNAME=	DenyHosts-${PORTVERSION}

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Script to thwart ssh attacks

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	DenyHosts

USE_RC_SUBR=	denyhosts
SUB_FILES=	pkg-message

PORTDOCS=	CHANGELOG.txt LICENSE.txt README.txt

post-patch:
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' \
		${WRKSRC}/daemon-control-dist \
		${WRKSRC}/denyhosts.cfg-dist \
		${WRKSRC}/setup.py
	@${RM} ${WRKSRC}/scripts/restricted_from_passwd.py.orig

post-install:
	${INSTALL_DATA} ${WRKSRC}/denyhosts.cfg-dist ${PREFIX}/etc/denyhosts.conf-dist
	[ -f ${PREFIX}/etc/denyhosts.conf ] || \
		${INSTALL_DATA} ${WRKSRC}/denyhosts.cfg-dist ${PREFIX}/etc/denyhosts.conf
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
. for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
. endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
