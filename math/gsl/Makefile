# New ports collection makefile for:	gsl
# Date created:				15 Feb 2000
# Whom:					Andrew L. Neporada <andrew@chg.ru>
#
# $FreeBSD$
#

PORTNAME=	gsl
PORTVERSION=	0.9.4
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEWARE}
MASTER_SITE_SUBDIR=	${PORTNAME}
.if !defined(NOPORTDOCS)
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${GSLREF}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
.endif

MAINTAINER=	vlad@ariel.phys.wesleyan.edu

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

MAN1=		gsl-config.1 gsl-randist.1 gsl-histogram.1
MAN3=		gsl.3

GSLREF=		gsl-ref.ps.gz
IGNOREFILES=	${GSLREF}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/gsl
	${INSTALL_DATA} ${_DISTDIR}/${GSLREF} ${PREFIX}/share/doc/gsl
	${GUNZIP_CMD} ${PREFIX}/share/doc/gsl/${GSLREF}
.endif

.include <bsd.port.mk>
