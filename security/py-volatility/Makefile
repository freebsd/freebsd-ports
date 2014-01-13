# Created by: antoine@FreeBSD.org
# $FreeBSD$

PORTNAME=	volatility
PORTVERSION=	2.3.1
CATEGORIES=	security python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Advanced memory forensics framework

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}distorm>=0:${PORTSDIR}/devel/py-distorm \
		${PYTHON_PKGNAMEPREFIX}imaging>=0:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_PKGNAMEPREFIX}pycrypto>=0:${PORTSDIR}/security/py-pycrypto \
		${PYTHON_PKGNAMEPREFIX}yara>=0:${PORTSDIR}/security/py-yara \
		${PYTHON_PKGNAMEPREFIX}openpyxl>=0:${PORTSDIR}/textproc/py-openpyxl

USE_PYTHON=	2
USE_PYDISTUTILS=yes
PYDISTUTILS_AUTOPLIST=yes

OPTIONS_DEFINE=	DOCS

DATADIR=	${PREFIX}/share/py-${PORTNAME}
PORTDOCS=	AUTHORS.txt CHANGELOG.txt CREDITS.txt README.txt
DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

.include <bsd.port.pre.mk>

PYDISTUTILS_INSTALLARGS+=--install-data ${DATADIR}

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.post.mk>
