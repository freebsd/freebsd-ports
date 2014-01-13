# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	analyzemft
PORTVERSION=	2.0.10
CATEGORIES=	sysutils devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	analyzeMFT-${PORTVERSION}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Analyze the MFT from a NTFS filesystem

LICENSE=	CPL
LICENSE_NAME=	Common Public License
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USE_PYTHON=	2
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=analyzeMFT

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
PORTDOCS=	README.txt

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
