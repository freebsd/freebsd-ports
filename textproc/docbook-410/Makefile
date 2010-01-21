# New ports collection makefile for:	docbook-410
# Date created:		26 June 2000
# Whom:			murray
#
# Based on nik's docbook-310 port
#
# $FreeBSD$
#

PORTNAME=	docbook
PORTVERSION=	4.1
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	http://www.docbook.org/sgml/4.1/
DISTNAME=	docbk41
EXTRACT_ONLY=	# empty

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	V4.1 of the DocBook DTD, designed for technical documentation

RUN_DEPENDS=	${ISOCAT}:${PORTSDIR}/textproc/iso8879 \
		${XMLCATMGR}:${PORTSDIR}/textproc/xmlcatmgr

USE_ZIP=	yes
NO_MTREE=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PLIST_SUB=	DTD_NAME=${PORTNAME}
PLIST_SUB+=	DTD_VERSION=${PORTVERSION}
PLIST_SUB+=	XMLCATMGR=${XMLCATMGR}
PLIST_SUB+=	CATALOG_PORTS_SGML=${CATALOG_PORTS_SGML}

INSTDIR=	${PREFIX}/share/sgml/docbook
ISOCAT=		${PREFIX}/share/sgml/iso8879/catalog
XMLCATMGR=	${LOCALBASE}/bin/xmlcatmgr
CATALOG_PORTS_SGML=	${PREFIX}/share/sgml/catalog.ports

LATEST_LINK=	docbook-410

pre-su-install:
	@${MKDIR} ${INSTDIR}/${PORTVERSION}

do-install:
	@${UNZIP_CMD} -a -q -o ${DISTDIR}/${DISTFILES} -d ${INSTDIR}/${PORTVERSION}
	@${INSTALL_DATA} ${FILESDIR}/catalog ${INSTDIR}/${PORTVERSION}/catalog
	@${ECHO_CMD} "CATALOG \"${ISOCAT}\"" >> ${INSTDIR}/${PORTVERSION}/catalog
	@${CHMOD} ${SHAREMODE} ${INSTDIR}/${PORTVERSION}/*
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${INSTDIR}

post-install:
	@-${XMLCATMGR} -sc ${CATALOG_PORTS_SGML} add CATALOG ${PORTNAME}/${PORTVERSION}/catalog

.include <bsd.port.mk>
