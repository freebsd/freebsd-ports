# New ports collection makefile for:   gsl
# Date created:                        15 Feb 2000
# Whom:                                Andrew L. Neporada <andrew@chg.ru>
#
# $FreeBSD$
#

PORTNAME=	gsl
PORTVERSION=	0.5
CATEGORIES=	math
MASTER_SITES=	ftp://sourceware.cygnus.com/pub/gsl/ \
		ftp://ftp.funet.fi/pub/mirrors/sourceware.cygnus.com/pub/gsl/ \
		ftp://ftp.chg.ru/pub/math/gsl/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${GSLREF}

MAINTAINER=	andrew@chg.ru

GNU_CONFIGURE=	yes
.if !defined(NOPORTDOCS)
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
.endif

GSLREF=		gsl-ref.ps.gz

post-install:
	strip ${PREFIX}/bin/gsl-histogram ${PREFIX}/bin/gsl-randist
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/gsl
	${INSTALL_MAN} ${DISTDIR}/gsl-ref.ps.gz ${PREFIX}/share/doc/gsl
	${GUNZIP_CMD} ${PREFIX}/share/doc/gsl/gsl-ref.ps.gz
.endif

.include <bsd.port.mk>
