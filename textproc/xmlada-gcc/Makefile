# New ports collection makefile for:    xmlada-gcc
# Date created:        24 Dec 2006
# Whom:                hopet@ics.muni.cz
#
# $FreeBSD$
#

PORTNAME=	xmlada
PORTVERSION=	5.0.4
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gnuada
PKGNAMESUFFIX=	-gcc
DISTNAME=	gnat-gcc-xmlada-4.1.1_gnat_5.04a-r6.src
EXTRACT_SUFX=	.rpm

MAINTAINER=	hopet@ics.muni.cz
COMMENT=	An XML parsing library for Ada 95, port for lang/gnat-gcc41

BUILD_DEPENDS=	${LOCALBASE}/bin/gcc41/gcc41:${PORTSDIR}/lang/gnat-gcc41

EXTRACT_DEPENDS=	rpm2cpio.pl:${PORTSDIR}/archivers/rpm2cpio

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	makeinfo:${PORTSDIR}/print/texinfo \
		pdftex:${PORTSDIR}/print/teTeX
.endif

WRKSRC=		${WRKDIR}/xmlada-gnat-5_04a

CONFLICTS=	xmlada-[0-9]*

CC=		${LOCALBASE}/bin/gcc41/gcc41
CONFIGURE_ENV+=	PATH=${LOCALBASE}/bin/gcc41:${PATH} CC=${LOCALBASE}/bin/gcc41/gcc41
MAKE_ENV+=	PATH=${LOCALBASE}/bin/gcc41:${PATH}

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

ADACFLAGS?=	# none
CFLAGS=		${ADACFLAGS}

XMLADAPKGNAME=	xmlada-gnat-5_04a.tar.bz2

do-extract:
	if [ ! -d ${WRKDIR} ]; then \
		${MKDIR} ${WRKDIR}; \
	fi
	( cd ${WRKDIR} && \
	rpm2cpio.pl <${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} | ${CPIO} -i ${XMLADAPKGNAME} && \
	tar jxf ${XMLADAPKGNAME} )

.include <bsd.port.mk>
