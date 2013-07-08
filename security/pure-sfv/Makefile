# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	pure-sfv
PORTVERSION=	0.3
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}_src

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Utility to test and create .sfv files

LICENSE=	GPLv2

USES=		gmake
MAKE_JOBS_SAFE=	yes

WRKSRC=		${WRKDIR}

PLIST_FILES=	bin/pure-sfv
PORTDOCS=	ReadMe.txt

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -E 's/^(CFLAGS|CC)[ +=]*/\1?=/' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
