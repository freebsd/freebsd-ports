# New ports collection makefile for:   numdiff
# Date created:        18 October 2006
# Whom:                Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	numdiff
PORTVERSION=	3.0.2
CATEGORIES=	math textproc
MASTER_SITES=	http://download.savannah.gnu.org/releases/numdiff/

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Compare putatively similar files, ignoring small numeric differences

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--exec-prefix=${PREFIX} --infodir=${PREFIX}/info LIBS=-lm
WRKSRC=	${WRKDIR}/${PORTNAME}

INFO=	numdiff

pre-install:
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e 's,$$[(]MKDIR[)] $$[(]DOCDIR[)],,' \
		-e 's,$$[(]INSTALL[)] $$[(]DOCS[)] $$[(]DOCDIR[)],,' \
		${WRKSRC}/Makefile
.endif

post-configure:
	${REINPLACE_CMD} -e 's,$$[(]prefix[)]/doc/$$[(]PACKAGE[)],${DOCSDIR},' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
