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

USE_BZIP2=	yes

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
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
