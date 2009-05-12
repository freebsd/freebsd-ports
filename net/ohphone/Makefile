# New ports collection makefile for:	ohphone
# Date created:		Fri Aug 18 19:29:00 BST 2000
# Whom:			Roger Hardiman <roger@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ohphone
PORTVERSION=	1.4.5
PORTREVISION=	5
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.frm2.tum.de/pub/jpulz/FreeBSD/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	H323 Video Conferencing Program, compatible with NetMeeting

LIB_DEPENDS=	h323_r.1:${PORTSDIR}/net/openh323

USE_BISON=	build
USE_GMAKE=	yes
ALL_TARGET=	optshared
MAKE_ENV=	PWLIBDIR=${LOCALBASE}/share/pwlib \
		OPENH323DIR=${LOCALBASE}/share/openh323 \
		SYSLIBDIR=${LOCALBASE}/lib
MAKE_ARGS=	OSTYPE=${OPSYS} MACHTYPE=${ARCH:S/i386/x86/} \
		OSRELEASE=${OSVERSION} CPLUS=${CXX}

MAN1=		ohphone.1

PLIST_SUB=	PORTNAME=${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/openh323
EXAMPLESDIR=	${PREFIX}/share/examples/openh323

.include <bsd.port.pre.mk>

.if ${ARCH} == sparc64 && ${OSVERSION} <= 700003
BROKEN=	does not link due to missing symbol in default thread library
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/obj_r/ohphone ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ohphone.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/ReadMe.txt ${DOCSDIR}/${PORTNAME}
.endif
	${MKDIR} ${EXAMPLESDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/check_listen.awk ${EXAMPLESDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/regtest ${EXAMPLESDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/stresstest ${EXAMPLESDIR}/${PORTNAME}

.include <bsd.port.post.mk>
