# New ports collection makefile for:    fftpack
# Version required:     ?
# Date created:         31 October 1996
# Whom:			Pedro Giffuni S.
#
# $Id: Makefile,v 1.5 1997/11/16 09:48:03 fenner Exp $
#

DISTNAME=	bihar
PKGNAME=	fftpack-1.0
CATEGORIES=	math
MASTER_SITES=	ftp://netlib.bell-labs.com/netlib/
EXTRACT_SUFX=	.tar

MAINTAINER=	giffunip@asme.org

# ${DISTFILES} is automatically created from the directory contents
IGNOREFILES=	${DISTFILES}
EXTRACT_BEFORE_ARGS=	-xf

post-extract:
	gunzip $(WRKSRC)/*.f.gz

pre-build:
	${RM} $(WRKSRC)/.depend
	${CP} ${FILESDIR}/makefile.lib ${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} $(PREFIX)/share/doc/fftpack
	-${GZIP_CMD} ${GZIP} ${WRKSRC}/fft.doc
	${CP} $(WRKSRC)/fft.doc.gz $(PREFIX)/share/doc/fftpack/
.endif
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
