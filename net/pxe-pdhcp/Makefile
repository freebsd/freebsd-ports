PORTNAME=	pxe-pdhcp
PORTVERSION=	0.0.2007
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://people.allbsd.org/~hrs/FreeBSD/

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Preboot Execution Environment server
WWW=		https://github.com/frsyuki/pxe-pdhcp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/README.md

WRKSRC=		${WRKDIR}/frsyuki-${PORTNAME}-a201b88
USES=		uidfix
SUB_FILES=	Makefile
MAKE_ENV=	PORTDOCS=${PORT_OPTIONS:MDOCS}
PLIST_FILES=	sbin/${PORTNAME} share/man/man8/${PORTNAME}.8.gz

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

pre-build:
	@${INSTALL_DATA} ${WRKDIR}/Makefile ${FILESDIR}/${PORTNAME}.8 ${WRKSRC}

.include <bsd.port.mk>
