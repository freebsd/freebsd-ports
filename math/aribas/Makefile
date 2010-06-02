# New ports collection makefile for:	aribas
# Date created:		2007-06-19
# Whom:			Lars Engels <lme@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	aribas
PORTVERSION=	1.64
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.mathematik.uni-muenchen.de/pub/forster/aribas/UNIX_LINUX/ \
		http://bsd-geek.de/FreeBSD/distfiles/

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Interpreter for big integer/multi-precision floating point arithmetic

BUILD_WRKSRC=	${WRKSRC}/src

PLIST_FILES=	bin/aribas
PORTDOCS=	README aribas.doc aribas.man aribas.tut
PORTEXAMPLES=	README factor.ari pi.ari queens.ari
MAN1=		aribas.1

post-patch:
	@${REINPLACE_CMD} -e '/^CC/d;' \
	       -e '/^CFLAGS/{s/=/+=/;s/-O -v//;}' \
		-e 's/CC) -o/CC) $$(CFLAGS) -o/' ${BUILD_WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/aribas ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 ${MAN1PREFIX}/man/man1/
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S|^|${WRKSRC}/examples/|} ${EXAMPLESDIR}
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
