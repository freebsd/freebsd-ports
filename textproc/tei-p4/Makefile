# New ports collection makefile for:	tei-p4
# Date created:				29 April 2002
# Whom:					Henrik Motakef
#
# $FreeBSD$
#

PORTNAME=	tei
PORTVERSION=	p4
CATEGORIES=	textproc
MASTER_SITES=	http://www.tei-c.org/P4X/DTD/
DISTNAME=	dtd

MAINTAINE=	henrik.motakef@web.de

RUN_DEPENDS=	${MKCATALOG}:${PORTSDIR}/textproc/mkcatalog

USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PLIST_SUB=	DTD_NAME=${PORTNAME} DTD_VERSION=${PORTVERSION} \
		MKCATALOG=${MKCATALOG}

DTD=		dtd.zip
SGMLDIR=	${PREFIX}/share/sgml
INSTDIR=	${SGMLDIR}/${PORTNAME}/${PORTVERSION}
MKCATALOG=	${PREFIX}/sbin/mkcatalog

pre-install:
	@[ -d ${INSTDIR} ] || ${MKDIR} ${INSTDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.dtd ${INSTDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ent ${INSTDIR}
	${INSTALL_DATA} ${WRKSRC}/*.dec ${INSTDIR}
	${INSTALL_DATA} ${WRKSRC}/teicatalog.xml ${INSTDIR}
	${SED} -e "s!&DTDpath;!${INSTDIR}/!" ${WRKSRC}/catalog.tei > ${INSTDIR}/catalog

post-install:
	@${MKCATALOG} -q install ${PORTNAME}/${PORTVERSION}

.include <bsd.port.mk>
