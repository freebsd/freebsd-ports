# Created by: Marcin Jessa <yazzy@yazzy.org>
# $FreeBSD$

PORTNAME=	Impacket
PORTVERSION=	0.9.9.9
CATEGORIES=	net python
MASTER_SITES=	http://corelabs.coresecurity.com/index.php?module=Wiki&action=attachment&type=tool&page=Impacket&file=
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	impacket-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Collection of Python classes providing access to network packets

LICENSE=	AL11
LICENSE_NAME=	Apache License version 1.1
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pcapy.so:${PORTSDIR}/net/py-pcapy

FETCH_BEFORE_ARGS=-o ${DISTFILES}
WRKSRC=		${WRKDIR}/impacket
USE_DOS2UNIX=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGVERSION=0.9.9.0-dev
PORTDOCS=	README

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
