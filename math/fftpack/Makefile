# New ports collection makefile for:    fftpack
# Version required:     ?
# Date created:         31 October 1996
# Whom:			Pedro Giffuni S.
#
# $Id: Makefile,v 1.7 1998/10/09 03:36:39 asami Exp $
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

.include <bsd.port.pre.mk>

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
.if ${PORTOBJFORMAT} == "aout"
	${LN} -sf libbihar.so.1 ${PREFIX}/lib/libbihar.so
.endif
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.post.mk>
