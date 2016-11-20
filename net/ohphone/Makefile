# Created by: Roger Hardiman <roger@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ohphone
PORTVERSION=	1.4.5
PORTREVISION=	10
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.frm2.tum.de/pub/jpulz/FreeBSD/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	H323 Video Conferencing Program, compatible with NetMeeting

LIB_DEPENDS=	libh323_r.so:net/openh323

USES=		bison gmake
ALL_TARGET=	optshared
MAKE_ENV=	PWLIBDIR=${LOCALBASE}/share/pwlib \
		OPENH323DIR=${LOCALBASE}/share/openh323 \
		SYSLIBDIR=${LOCALBASE}/lib
MAKE_ARGS=	OSTYPE=${OPSYS} MACHTYPE=${ARCH:S/i386/x86/} \
		OSRELEASE=${OSVERSION} CPLUS=${CXX}
USE_GCC=	any

PLIST_SUB=	PORTNAME=${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/openh323
EXAMPLESDIR=	${PREFIX}/share/examples/openh323

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz
PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/obj_r/ohphone ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ohphone.1 ${STAGEDIR}${PREFIX}/man/man1
	${MKDIR} ${STAGEDIR}${DOCSDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/ReadMe.txt ${STAGEDIR}${DOCSDIR}/${PORTNAME}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/check_listen.awk ${STAGEDIR}${EXAMPLESDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/regtest ${STAGEDIR}${EXAMPLESDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/stresstest ${STAGEDIR}${EXAMPLESDIR}/${PORTNAME}

.include <bsd.port.mk>
