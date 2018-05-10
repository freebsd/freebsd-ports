# Created by: Thierry Dussuet <dussuett@wigwam.ethz.ch>
# $FreeBSD$

PORTNAME=	ods2
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.lugs.ch/~dussuett/
DISTNAME=	ods2

MAINTAINER=	pzn.unixbsd@gmail.com
COMMENT=	Utility for manipulating ODS-2 filesystems

USES=		zip
NO_WRKSUBDIR=	yes
MAKEFILE=	makefile.unix
MAKE_ARGS=	CCFLAGS="${CFLAGS}"

PLIST_FILES=	sbin/ods2
PORTDOCS=	aareadme.too aareadme.txt

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|cc |${CC} |; /-oods2/ s|vmstime\.o|& -lcompat|' \
		${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ods2 ${STAGEDIR}${PREFIX}/sbin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
