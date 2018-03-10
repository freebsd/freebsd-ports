# Created by: jh@jameshoward.us
# $FreeBSD$

PORTNAME=	x12arima
PORTVERSION=	0.3
PORTREVISION=	7
CATEGORIES=	math finance
MASTER_SITES=	http://www.census.gov/ts/x12a/v03/unix/
DISTFILES=	omegav03src.tar.gz
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	jh@jameshoward.us
COMMENT=	X-12-ARIMA seasonal adjustment program

USES=		fortran
NO_WRKSUBDIR=	yes
MAKEFILE=	makefile.lnx

PLIST_FILES=	bin/x12a

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS} || make(makesum)
DISTFILES+=	docsv03.tar.gz
.endif

PORTDOCS=	ReleaseNotesVersion03.pdf qref03unix.pdf x12adocV03.pdf

.if ${PORT_OPTIONS:MDOCS}
post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/docs/|} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
