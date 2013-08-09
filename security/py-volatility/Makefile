# Created by: antoine@FreeBSD.org
# $FreeBSD$

PORTNAME=	volatility
PORTVERSION=	2.2
CATEGORIES=	security python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Advanced memory forensics framework

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycrypto>=0:${PORTSDIR}/security/py-pycrypto \
		${PYTHON_PKGNAMEPREFIX}distorm>=0:${PORTSDIR}/devel/py-distorm \
		${PYTHON_PKGNAMEPREFIX}yara>=0:${PORTSDIR}/security/py-yara

OPTIONS_DEFINE=	DOCS

USE_PYTHON=	-2.7
USE_PYDISTUTILS=easy_install

OPTIONS_DEFINE=	DOCS

PORTDOCS=	AUTHORS.txt CHANGELOG.txt CREDITS.txt README.txt
DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
