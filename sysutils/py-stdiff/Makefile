# New ports collection makefile for:	py-stdiff
# Date created:				11 Dec 2010
# Whom:					Marcelo Araujo <araujo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		stdiff
PORTVERSION=		0.2.1
CATEGORIES=		sysutils python
MASTER_SITES=		SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}/

MAINTAINER=		araujo@FreeBSD.org
COMMENT=		Spot The Difference is a file integrity checker.

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	$(INSTALL_MAN) ${WRKSRC}/INSTALL.txt ${DOCSDIR}/
	$(INSTALL_MAN) ${WRKSRC}/LICENSE.txt ${DOCSDIR}/
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} docs ${DOCSDIR}/)
.endif
	@if [ ! -f ${PREFIX}/etc/stdiff.conf ]; then \
		${CP} -p ${PREFIX}/etc/stdiff.conf.sample \
		${PREFIX}/etc/stdiff.conf; fi
.include <bsd.port.mk>
