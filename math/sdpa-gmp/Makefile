# New ports collection makefile for:    sdpa-gmp
# Date created:                         2008/4/11
# Whom:                                 NAKATA, Maho <maho@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sdpa-gmp
PORTVERSION=	7.1.2
PORTREVISION=	5
CATEGORIES=	math
MASTER_SITES=	http://sdpa.indsys.chuo-u.ac.jp/sdpa/files/
DISTFILES=	${SRCFILE} ${MANUALFILE}
DIST_SUBDIR=	sdpa
EXTRACT_ONLY=	${SRCFILE}

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Multi precision arithmetic version of math/sdpa

.include <bsd.port.pre.mk>

SRCDATE=	20091005
MANDATE=	20080618
MANUALVER=	7.1.1
SRCFILE=	${PORTNAME}.${PORTVERSION}.src.${SRCDATE}.tar.gz
MANUALFILE=	sdpa.${MANUALVER}.manual.${MANDATE}.pdf
GNU_CONFIGURE=	yes
LIB_DEPENDS+=	spooles:${PORTSDIR}/math/spooles \
		gmp.10:${PORTSDIR}/math/gmp \
		mpfr.4:${PORTSDIR}/math/mpfr

CONFIGURE_ARGS+= --with-system-spooles
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/spooles
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/spooles
CXXFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/spooles

PLIST_SUB+=	MANUALFILE=${MANUALFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sdpa_gmp ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA}    ${WRKSRC}/param.sdpa ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${MANUALFILE} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
