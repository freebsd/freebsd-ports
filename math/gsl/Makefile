# New ports collection makefile for:	gsl
# Date created:				15 Feb 2000
# Whom:					Andrew L. Neporada <andrew@chg.ru>
#
# $FreeBSD$
#

PORTNAME=	gsl
PORTVERSION=	1.3
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEWARE}
MASTER_SITE_SUBDIR=	${PORTNAME}
.if !defined(NOPORTDOCS)
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${GSLREF} ${GSLREFHTML}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
.endif

MAINTAINER=	vlad@ariel.phys.wesleyan.edu

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

MAN1=		gsl-config.1 gsl-randist.1 gsl-histogram.1
MAN3=		gsl.3

GSLREF=		gsl-ref.ps.gz
GSLREFHTML=	gsl-ref-html.tar.gz
IGNOREFILES=	${GSLREF} ${GSLREFHTML}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/gsl
	${INSTALL_DATA} ${_DISTDIR}/${GSLREF} ${PREFIX}/share/doc/gsl
	${GUNZIP_CMD} ${PREFIX}/share/doc/gsl/${GSLREF}
	tar xfz ${_DISTDIR}/${GSLREFHTML} -C ${PREFIX}/share/doc/gsl
	cd ${PREFIX}/share/doc/gsl && ${LN} -s gsl-ref-html html
.endif

.include <bsd.port.mk>
