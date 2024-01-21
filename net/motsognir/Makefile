PORTNAME=	motsognir
PORTVERSION=	1.0.13
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/v${PORTVERSION}

MAINTAINER=	kaltheat@gmail.com
COMMENT=	Full-featured gopher server without dependencies
WWW=		https://sourceforge.net/projects/motsognir/

LICENSE=	MIT

USES=		tar:xz
USE_RC_SUBR=	motsognir

SUB_FILES=	pkg-message

PLIST_FILES=	bin/motsognir \
		"@sample etc/motsognir.conf.sample" \
		share/man/man8/motsognir.8.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/motsognir ${STAGEDIR}${PREFIX}/bin/motsognir
	${INSTALL_DATA} ${WRKSRC}/motsognir.conf ${STAGEDIR}${PREFIX}/etc/motsognir.conf.sample
	${INSTALL_MAN} ${WRKSRC}/motsognir.8.gz ${STAGEDIR}${PREFIX}/share/man/man8/motsognir.8.gz

.include <bsd.port.mk>
