# New ports collection makefile for:   gsl
# Date created:                        15 Feb 2000
# Whom:                                Andrew L. Neporada <andrew@chg.ru>
#
# $FreeBSD$
#

PORTNAME=	gsl
PORTVERSION=	0.6
CATEGORIES=	math
MASTER_SITES=	ftp://sourceware.cygnus.com/pub/gsl/ \
		ftp://ftp.freesoftware.com/pub/sourceware/gsl/ \
		ftp://sunsite.org.uk/Mirrors/sourceware.cygnus.com/pub/gsl/ \
		ftp://ftp.funet.fi/pub/mirrors/sourceware.cygnus.com/pub/gsl/ \
		ftp://ftp.chg.ru/pub/math/gsl/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${GSLREF}
.if !defined(NOPORTDOCS)
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
.endif

MAINTAINER=	andrew@chg.ru

USE_LIBTOOL=	yes
GSLREF=		gsl-ref.ps.gz

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/gsl
	${INSTALL_MAN} ${DISTDIR}/${GSLREF} ${PREFIX}/share/doc/gsl
	${GUNZIP_CMD} ${PREFIX}/share/doc/gsl/${GSLREF}
.endif

.include <bsd.port.mk>
