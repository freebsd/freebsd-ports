# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libieee1284
PORTVERSION=	0.2.10
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	http://cyberelk.net/tim/data/libieee1284/stable/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IEEE 1284 communication library

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	i386

USES=		libtool tar:bzip2
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

PORTDOCS=	README README.FreeBSD

OPTIONS_DEFINE=	DOCS PYTHON
OPTIONS_SUB=	yes

PYTHON_USES=	python
PYTHON_CFLAGS=	-I${PYTHON_INCLUDEDIR}
PYTHON_LDFLAGS=	-L${PYTHON_LIBDIR}
PYTHON_CONFIGURE_ON=	--with-python=yes
PYTHON_CONFIGURE_OFF=	--with-python=no

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
