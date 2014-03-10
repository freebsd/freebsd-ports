# Created by: jh@jameshoward.us
# $FreeBSD$

PORTNAME=	x12arima
PORTVERSION=	0.3
PORTREVISION=	2
CATEGORIES=	math finance
MASTER_SITES=	http://www.census.gov/ts/x12a/v03/unix/
DISTFILES=	omegav03src.tar.gz
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	jh@jameshoward.us
COMMENT=	X-12-ARIMA seasonal adjustment program

USES=		fortran
NO_WRKSUBDIR=	yes
MAKEFILE=	makefile.lnx
NO_STAGE=	yes

PLIST_FILES=	bin/x12a

.ifndef(NOPORTDOCS) || make(makesum)
DISTFILES+=	docsv03.tar.gz
.endif

.ifndef(NOPORTDOCS)
PORTDOCS=	ReleaseNotesVersion03.pdf qref03unix.pdf x12adocV03.pdf

post-install:
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/docs && ${INSTALL_MAN} ${PORTDOCS} ${DOCSDIR})

.endif
.include <bsd.port.mk>
