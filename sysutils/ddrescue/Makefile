# New ports collection makefile for:	ddrescue
# Date created:		16 August 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ddrescue
DISTVERSION=	1.11
CATEGORIES=	sysutils
MASTER_SITES=	GNU

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Data recovery tool

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	CC="${CC}" CXX="${CXX}" CFLAGS="${CFLAGS}"\
		CXXFLAGS="${CXXFLAGS}"
USE_GZIP=	yes
PLIST_FILES=	bin/${PORTNAME}
MAN1=	${PORTNAME}.1
INFO=	${PORTNAME}
PORTDOCS=	AUTHORS ChangeLog NEWS README

post-patch:
	@${REINPLACE_CMD} -e 's|LONG_LONG|LLONG|' \
		${WRKSRC}/main.cc ${WRKSRC}/rescuebook.cc

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	@${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 ${MAN1PREFIX}/man/man1/
	@${INSTALL_DATA} ${WRKSRC}/doc/${PORTNAME}.info ${PREFIX}/${INFO_PATH}/
.ifndef NOPORTDOCS
	@${INSTALL} -d ${DOCSDIR}/
	@cd ${WRKSRC}/&&${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
