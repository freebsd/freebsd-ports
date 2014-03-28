# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libieee1284
PORTVERSION=	0.2.10
CATEGORIES=	sysutils
MASTER_SITES=	http://cyberelk.net/tim/data/libieee1284/stable/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IEEE1284 communication library

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	i386

USES=		tar:bzip2
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

PORTDOCS=	README README.FreeBSD

OPTIONS_DEFINE=	PYTHON
OPTIONS_SUB=	yes

PYTHON_USE=	PYTHON=yes
PYTHON_CFLAGS=	-I${PYTHON_INCLUDEDIR}
PYTHON_LDFLAGS=	-L${PYTHON_LIBDIR}
PYTHON_CONFIGURE_ON=	--with-python=yes
PYTHON_CONFIGURE_OFF=	--with-python=no

post-patch:
	@${REINPLACE_CMD} -E -e 's,(objformat=).*,\1elf,' \
		${WRKSRC}/configure

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
