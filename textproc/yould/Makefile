# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	yould
PORTVERSION=	0.3.7
CATEGORIES=	textproc
MASTER_SITES=	CHEESESHOP/source/y/${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Pronounceable word generator

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install
PYDISTUTILS_INSTALLARGS=-Z -O 1 -N -S ${PYTHON_SITELIBDIR} ${WRKSRC}/dist/${PYEASYINSTALL_EGG}
PORTDOCS=	NEWS.txt README.txt

.ifndef NOPORTDOCS
NO_STAGE=	yes
post-install:
	@${INSTALL} -d ${DOCSDIR}/
	@cd ${WRKSRC}/&&${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
