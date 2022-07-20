PORTNAME=	pp
PORTVERSION=	1.03
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://de.nologin.ru/distfiles/sysutils/pp/

MAINTAINER=	a.arepo@gmail.com
COMMENT=	Small and fast progress bar for pipe

LICENSE=	BSD3CLAUSE

USES=		tar:bzip2
MAKE_ARGS=	PREFIX="${STAGEDIR}${PREFIX}"

PLIST_FILES=	bin/pp

post-patch:
	@${REINPLACE_CMD} -e 's,char opt,int opt,' ${WRKSRC}/src/main.c

.include <bsd.port.mk>
