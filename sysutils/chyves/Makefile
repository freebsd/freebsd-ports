PORTNAME=	chyves
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.0
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	bhyve front-end manager
WWW=		http://chyves.org

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes

NO_BUILD=	yes
NO_ARCH=	yes

MAKE_ARGS+=	-e MAN_DIR=share/man/man8

post-patch:
	${REINPLACE_CMD} 's%\$$(PREFIX)%${STAGEDIR}/$$(PREFIX)%g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
