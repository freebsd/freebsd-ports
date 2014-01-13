# Created by: Andrej Zverev <az@inec.ru>
# $FreeBSD$

PORTNAME=	svnmailer
DISTVERSION=	1.1.0-dev-r1373
PORTREVISION=	5
CATEGORIES=	mail python
MASTER_SITES=	http://storage.perlig.de/${PORTNAME}/
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to post subversion repository commit information

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}subversion>0:${PORTSDIR}/devel/py-subversion
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_BZIP2=	yes
USE_PYTHON=	2
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGVERSION=	${DISTVERSION}

MAN1=		svn-mailer.1

PORTDOCS=	*

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MDOCS}
PYDISTUTILS_INSTALLARGS+=	--no-install-docs
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e "1s|^.*|#!${PYTHON_CMD}|" \
		-e 's,distutils\.command import install ,setuptools\.command import install ,' \
		${WRKSRC}/setup.py
	@${REINPLACE_CMD} -e "1s|^.*|#!${PYTHON_CMD}|" ${WRKSRC}/src/svn-mailer

.include <bsd.port.mk>
