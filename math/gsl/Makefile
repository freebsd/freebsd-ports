# New ports collection makefile for:	gsl
# Date created:				15 Feb 2000
# Whom:					Andrew L. Neporada <andrew@chg.ru>
#
# $FreeBSD$
#

PORTNAME=	gsl
PORTVERSION=	1.8
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GNU:S/$/:gsl/} \
		http://www.gnu.org/software/${PORTNAME}/manual/:gslref
MASTER_SITE_SUBDIR=	${PORTNAME}/:gsl
.if !defined(NOPORTDOCS)
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:gsl \
		${GSLREF}:gslref
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
.endif

MAINTAINER=	rainer.alves@gmail.com
COMMENT=	The GNU Scientific Library - mathematical libs

INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV+=	MAKEINFO='makeinfo --no-split'

MAN1=		gsl-config.1 gsl-randist.1 gsl-histogram.1
MAN3=		gsl.3
INFO=		gsl-ref

GSLREF=		gsl-ref.ps.gz
IGNOREFILES=	${GSLREF}

post-extract:
	@${RM} -f ${WRKSRC}/doc/gsl-ref.info*

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/gsl
	${INSTALL_DATA} ${_DISTDIR}/${GSLREF} ${PREFIX}/share/doc/gsl
	${GUNZIP_CMD} ${PREFIX}/share/doc/gsl/${GSLREF}
.endif

.include <bsd.port.mk>
