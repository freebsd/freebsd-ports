# New ports collection makefile for:    fftpack
# Date created:         31 October 1996
# Whom:			Pedro Giffuni S.
#
# $FreeBSD$
#

PORTNAME=	bihar
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	math
MASTER_SITES=	ftp://netlib.bell-labs.com/netlib/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Biharmonic equation in rectangular geometry and polar coordinates

LIB_DEPENDS=	linpack.3:${PORTSDIR}/math/linpack

# ${DISTFILES} is automatically created from the directory contents
IGNOREFILES=	${DISTFILES}
EXTRACT_CMD=	${TAR}
EXTRACT_BEFORE_ARGS=	-xf
EXTRACT_AFTER_ARGS=	# empty

USE_LDCONFIG=	yes
USE_FORTRAN=	yes

PORTDOCS=	fft.doc.gz

post-extract:
	${GUNZIP_CMD} $(WRKSRC)/*.f.gz

pre-build:
	${RM} $(WRKSRC)/.depend
	${CP} ${FILESDIR}/makefile.lib ${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	-${GZIP_CMD} ${GZIP} ${WRKSRC}/fft.doc
	${CP} $(WRKSRC)/fft.doc.gz ${DOCSDIR}
.endif

.include <bsd.port.mk>
