# New ports collection makefile for:    fftpack
# Version required:     ?
# Date created:         31 October 1996
# Whom:                 pgs
#
# $Id: Makefile,v 1.3 1997/07/17 15:12:55 max Exp $
#

DISTNAME=	fftpack
PKGNAME=	fftpack-1.0
CATEGORIES=	math
MASTER_SITES=	ftp://netlib.bell-labs.com/netlib/
EXTRACT_SUFX=	.tar

MAINTAINER=	ports@FreeBSD.org

# ${DISTFILES} is automatically created from the directory contents
IGNOREFILES=	${DISTFILES}
EXTRACT_BEFORE_ARGS=	-xvf

post-extract:
	gunzip $(WRKSRC)/*.f.gz

pre-build:
	${RM} $(WRKSRC)/.depend
	${CP} ${FILESDIR}/makefile.lib ${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} $(PREFIX)/share/doc/fftlib
	${CP} $(WRKSRC)/doc.gz $(PREFIX)/share/doc/fftlib/
.endif
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
