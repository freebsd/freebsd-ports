# New ports collection makefile for:	yould
# Date created:		23 June 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	yould
PORTVERSION=	0.3.7
CATEGORIES=	textproc
MASTER_SITES=	http://ygingras.net/files/ CENKES

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Pronounceable word generator

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install
PYDISTUTILS_INSTALLARGS=-Z -O 1 -N -S ${PYTHON_SITELIBDIR} ${WRKSRC}/dist/${PYEASYINSTALL_EGG}
PORTDOCS=	NEWS.txt README.txt

.ifndef NOPORTDOCS
post-install:
	@${INSTALL} -d ${DOCSDIR}/
	@cd ${WRKSRC}/&&${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
