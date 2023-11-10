PORTNAME=	mozplugger
PORTVERSION=	2.1.6
CATEGORIES=	www
MASTER_SITES=	http://mozplugger.mozdev.org/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Framework for loading web content in external viewers
WWW=		http://mozplugger.mozdev.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Obsolete, defunct as Mozilla Firefox dropped support for plugin interface as of ESR 60
EXPIRATION_DATE=2023-11-30

GNU_CONFIGURE=	yes
USES=		desthack gmake webplugin:native xorg
USE_XORG=	x11 xt
LLD_UNSAFE=	yes

WEBPLUGIN_FILES=mozplugger.so
MAKE_ENV=	WEBPLUGINS_DIR="${WEBPLUGIN_DIR}"
MAKE_ARGS=	root=${STAGEDIR}

post-patch:
	@${REINPLACE_CMD} -e 's|"/etc|"${PREFIX}/etc|g' \
		${WRKSRC}/mozplugger.c

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/mozplugger-*
	@${STRIP_CMD} ${STAGEDIR}${WEBPLUGIN_DIR}/*.so

.include <bsd.port.mk>
