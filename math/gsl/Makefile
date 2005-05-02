# New ports collection makefile for:	gsl
# Date created:				15 Feb 2000
# Whom:					Andrew L. Neporada <andrew@chg.ru>
#
# $FreeBSD$
#

PORTNAME=	gsl
PORTVERSION=	1.6
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEWARE}
MASTER_SITE_SUBDIR=	${PORTNAME}
.if !defined(NOPORTDOCS)
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${GSLREF}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
.endif

MAINTAINER=	jon.drews@gmail.com
COMMENT=	The GNU Scientific Library - mathematical libs

INSTALLS_SHLIB=	yes
USE_INC_LIBTOOL_VER=13
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV+=	MAKEINFO='makeinfo --no-split'

MAN1=		gsl-config.1 gsl-randist.1 gsl-histogram.1
MAN3=		gsl.3
INFO=		gsl-ref

GSLREF=		gsl-ref.ps.gz
IGNOREFILES=	${GSLREF}

post-extract:
	${RM} -f ${WRKSRC}/doc/gsl-ref.info*

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/gsl
	${INSTALL_DATA} ${_DISTDIR}/${GSLREF} ${PREFIX}/share/doc/gsl
	${GUNZIP_CMD} ${PREFIX}/share/doc/gsl/${GSLREF}
.endif

.include <bsd.port.mk>
