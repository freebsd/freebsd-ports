# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	cmospwd
PORTVERSION=	5.1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.cgsecurity.org/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	BIOS password recovery tool

LICENSE=	GPLv2

USES=		tar:bzip2

PLIST_FILES=	bin/cmospwd
PORTDOCS=	cmospwd.txt

ONLY_FOR_ARCHS=	i386 amd64

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
.if ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e "s/`${ECHO_CMD} -e '\r'`*$$//" \
		${WRKSRC}/cmospwd.txt
.endif

do-build:
	${CC} ${CFLAGS} ${WRKSRC}/src/${PORTNAME}.c -o ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
