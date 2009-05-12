# New ports collection makefile for:	openmcu
# Date created:		Wed Nov 22 08:57:55 GMT 2000
# Whom:			Roger Hardiman <roger@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	openmcu
PORTVERSION=	2.2.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	openh323
DISTNAME=	${PORTNAME}-v${PORTVERSION:S/./_/g}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OpenMCU hosts a conference call for H323 Video Conferencing users

LIB_DEPENDS=	h323_r.1:${PORTSDIR}/net/openh323

WRKSRC=		${WRKDIR}/${PORTNAME}_v${PORTVERSION:S/./_/g}

USE_BISON=	build
USE_GMAKE=	yes
ALL_TARGET=	optshared
MAKE_ENV=	PWLIBDIR=${LOCALBASE}/share/pwlib \
		OPENH323DIR=${LOCALBASE}/share/openh323 \
		SYSLIBDIR=${LOCALBASE}/lib
MAKE_ARGS=	OSTYPE=${OPSYS} MACHTYPE=${ARCH:S/i386/x86/} \
		OSRELEASE=${OSVERSION} CPLUS=${CXX}

MAN1=		openmcu.1

PLIST_SUB=	PORTNAME=${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/openh323
EXAMPLESDIR=	${PREFIX}/share/examples/openh323

.include <bsd.port.pre.mk>

.if ${ARCH} == sparc64
BROKEN=		Does not install
.endif

pre-install:
	@${SED}	-e 's|%%EXAMPLESDIR%%|${EXAMPLESDIR}|g' \
		-e 's|%%PORTNAME%%|${PORTNAME}|g' \
		${FILESDIR}/openmcu.ini.sample > ${WRKDIR}/openmcu.ini

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/obj_r/openmcu ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MAN1PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/ReadMe.txt ${DOCSDIR}/${PORTNAME}
.endif
	@${MKDIR} ${EXAMPLESDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/*.wav ${EXAMPLESDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKDIR}/openmcu.ini ${EXAMPLESDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/server.pem ${EXAMPLESDIR}/${PORTNAME}

.include <bsd.port.post.mk>
