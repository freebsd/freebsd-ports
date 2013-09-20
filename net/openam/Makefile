# Created by: Roger Hardiman <roger@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openam
PORTVERSION=	1.1.18
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://www.voxgratia.org/releases/
DISTNAME=	${PORTNAME}-v${PORTVERSION:S/./_/g}-src-
EXTRACT_SUFX=	tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	H323 Answer Machine

LIB_DEPENDS=	h323_r.1:${PORTSDIR}/net/openh323

WRKSRC=		${WRKDIR}/${PORTNAME}_v${PORTVERSION:S/./_/g}

USE_GMAKE=	yes
ALL_TARGET=	optshared
MAKE_ENV=	PWLIBDIR=${LOCALBASE}/share/pwlib \
		OPENH323DIR=${LOCALBASE}/share/openh323 \
		SYSLIBDIR=${LOCALBASE}/lib
MAKE_ARGS=	OSTYPE=${OPSYS} MACHTYPE=${ARCH:S/i386/x86/} \
		OSRELEASE=${OSVERSION} CPLUS=${CXX}

PLIST_SUB=	PORTNAME=${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/openh323

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/obj_r/openam ${PREFIX}/bin
	@${MKDIR} ${DOCSDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/ReadMe.txt ${DOCSDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/sample_message.wav ${DOCSDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/sample_message_g7231.wav ${DOCSDIR}/${PORTNAME}

.include <bsd.port.mk>
