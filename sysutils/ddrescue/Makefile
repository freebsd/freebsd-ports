# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ddrescue
PORTVERSION=	1.16
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	GNU

MAINTAINER=	jharris@widomaker.com
COMMENT=	Data recovery tool

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	DOCS

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	CC="${CC}" CXX="${CXX}" CFLAGS="${CFLAGS}" \
		CXXFLAGS="${CXXFLAGS}"

MAN1=		ddrescue.1 ddrescuelog.1
INFO=		ddrescue
PORTDOCS=	AUTHORS ChangeLog NEWS README
PLIST_FILES=	bin/ddrescue bin/ddrescuelog

.include <bsd.port.options.mk>

do-install:
.for i in ddrescue ddrescuelog
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/${i}.1 ${MAN1PREFIX}/man/man1
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/ddrescue.info ${PREFIX}/${INFO_PATH}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
