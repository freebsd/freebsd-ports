# New ports collection makefile for:	ddrescue
# Date created:		16 August 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ddrescue
PORTVERSION=	1.12
CATEGORIES=	sysutils
MASTER_SITES=	GNU

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Data recovery tool

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	CC="${CC}" CXX="${CXX}" CFLAGS="${CFLAGS}" \
		CXXFLAGS="${CXXFLAGS}"

MAN1=		${PORTNAME}.1
INFO=		${PORTNAME}
PORTDOCS=	AUTHORS ChangeLog NEWS README
PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 ${MAN1PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/doc/${PORTNAME}.info ${PREFIX}/${INFO_PATH}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
