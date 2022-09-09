PORTNAME=	iohyve
PORTVERSION=	0.7.9
CATEGORIES=	sysutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	bhyve manager utilizing ZFS and other FreeBSD tools
WWW=		https://github.com/pr1ntf/iohyve

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	pr1ntf

NO_ARCH=	yes

post-patch:
	${REINPLACE_CMD} 's%\$$(PREFIX)%${STAGEDIR}/$$(PREFIX)%g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
