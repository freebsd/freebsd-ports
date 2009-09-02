# New ports collection makefile for:	bsflite
# Date created:				3 June 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	bsflite
DISTVERSION=	0.84
CATEGORIES=	net-im
MASTER_SITES=	SF

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A lightweight command line AIM client

MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/bsflite %%EXAMPLESDIR%%/config-example
PLIST_DIRS=	%%EXAMPLESDIR%%
PORTDOCS=	COPYING ChangeLog README

post-patch:
	@${REINPLACE_CMD} -E '/^(CC|CFLAGS)/d' \
		${WRKSRC}/${MAKEFILE} \
		${WRKSRC}/imcomm/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bsflite ${PREFIX}/bin
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/config-example ${EXAMPLESDIR}

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
