PORTNAME=	radvd
PORTVERSION=	2.19
PORTREVISION=	4
CATEGORIES=	net
MASTER_SITES=	http://www.litech.org/radvd/dist/

PATCH_SITES=	https://github.com/${PORTNAME}-project/${PORTNAME}/commit/
PATCHFILES=	3f1aeb2.patch:-p1

MAINTAINER=	farrokhi@FreeBSD.org
COMMENT=	Linux/BSD IPv6 router advertisement daemon
WWW=		http://www.litech.org/radvd/

LICENSE=	RADVD
LICENSE_NAME=	RADVD License
LICENSE_FILE=	${WRKSRC}/COPYRIGHT
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
USES=		gmake pkgconfig
CONFIGURE_ARGS=	--program-transform-name=
USE_RC_SUBR=	radvd

PORTDOCS=	CHANGES COPYRIGHT INTRO.html README TODO

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_DATA} ${WRKSRC}/radvd.conf.example ${STAGEDIR}${PREFIX}/etc/radvd.conf.sample
	${INSTALL} -d ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S.^.${WRKSRC}/.} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
