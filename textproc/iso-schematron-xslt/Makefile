# $FreeBSD$

PORTNAME=	iso-schematron-xslt
PORTVERSION=	20130313
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.schematron.com/tmp/
DISTFILES=	iso-schematron-xslt1.zip \
		iso-schematron-xslt2.zip

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	The Leading Implementation of ISO Schematron

USES=		zip:infozip
NO_BUILD=	yes

do-extract:
	${MKDIR} ${WRKDIR}/xslt1
	${MKDIR} ${WRKDIR}/xslt2
	( cd ${WRKDIR}/xslt1 && ${UNZIP_CMD} ${DISTDIR}/iso-schematron-xslt1.zip )
	( cd ${WRKDIR}/xslt2 && ${UNZIP_CMD} ${DISTDIR}/iso-schematron-xslt2.zip )

INSTDIR=	share/xsl/iso-schematron
PLIST_SUB+=	INSTDIR="${INSTDIR}"

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${INSTDIR}/xslt1
	( ${FIND} ${WRKDIR}/xslt1 -type f -exec ${INSTALL_DATA} {} ${STAGEDIR}${PREFIX}/${INSTDIR}/xslt1/ \; )
	${MKDIR} ${STAGEDIR}${PREFIX}/${INSTDIR}/xslt2
	( ${FIND} ${WRKDIR}/xslt2 -type f -exec ${INSTALL_DATA} {} ${STAGEDIR}${PREFIX}/${INSTDIR}/xslt2/ \; )

.include <bsd.port.mk>
