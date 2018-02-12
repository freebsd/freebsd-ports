# Created by: Marcel Prisi <marcel.prisi@virtua.ch>
# $FreeBSD$

PORTNAME=	distcache
DISTVERSION=	1.5.1
CATEGORIES=	security www
MASTER_SITES=	SF/${PORTNAME}/2.%20${PORTNAME}-stable/${PORTVERSION} \
		http://osdn.dl.sourceforge.net/sourceforge/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Distributed OpenSSL session caching tools

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		libtool ssl tar:bzip2
USE_RC_SUBR=	dc_server
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --with-ssl=${OPENSSLBASE}
INSTALL_TARGET=	install-strip

SUB_LIST=	NAME=dc_server
PORTDOCS=	ANNOUNCE BUGS CHANGES FAQ README

OPTIONS_DEFINE=	DOCS

post-install:
	# INSTALL_TARGET=install-strip isn't working!  Brute force it
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
