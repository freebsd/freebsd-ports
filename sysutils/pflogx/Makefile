# ex:ts=8
# New ports collection makefile for:	pflogx
# Date created:			May 10 2006
# Whom:				clsung
#
# $FreeBSD$
#

PORTNAME=	pflogx
PORTVERSION=	0.86
CATEGORIES=	sysutils
MASTER_SITES=	http://akldev.free.fr/pflogx/releases/
DISTNAME=	${PORTNAME}_${PORTVERSION:S/.//}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Simple tool to export pf (packet filter) logs to XML files

WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS=	EXPAT	"Ability to merge new events (require expat) " Off

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600000
IGNORE=		only for 6.0 and above
.endif

.if defined(WITH_EXPAT)
LIB_DEPENDS=	expat:${PORTSDIR}/textproc/expat2
MAKE_ARGS+=	-DWITH_EXPAT \
		EXPAT_INCLUDEDIR=${LOCALBASE}/include \
		EXPAT_LIBDIR=${LOCALBASE}/lib
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/pflogx ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/dtd/* ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/xsl/* ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
