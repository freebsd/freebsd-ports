PORTNAME=	cmospwd
PORTVERSION=	5.1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.cgsecurity.org/ \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	BIOS password recovery tool

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	amd64 i386

USES=		tar:bzip2

PLIST_FILES=	bin/cmospwd
PORTDOCS=	cmospwd.txt

OPTIONS_DEFINE=	DOCS

post-patch-DOCS-on:
	@${REINPLACE_CMD} -e "s/`${ECHO_CMD} -e '\r'`*$$//" \
		${WRKSRC}/cmospwd.txt

do-build:
	${CC} ${CFLAGS} ${WRKSRC}/src/${PORTNAME}.c -o ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
