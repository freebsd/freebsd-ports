# New ports collection makefile for:	tei-p3
# Date created:				19 May 2002
# Whom:					Henrik Motakef <henrik.motakef@web.de>
#
# $FreeBSD$
#

PORTNAME=	tei
PORTVERSION=	p3
CATEGORIES=	textproc
MASTER_SITES=	http://www.tei-c.org/Vault/GL/
DISTNAME=	teip3dtd

MAINTAINER=	henrik.motakef@web.de

RUN_DEPENDS=	${MKCATALOG}:${PORTSDIR}/textproc/mkcatalog

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PLIST_SUB=	DTD_NAME=${PORTNAME} DTD_VERSION=${PORTVERSION} \
		MKCATALOG=${MKCATALOG}

SGMLDIR=	${PREFIX}/share/sgml
INSTDIR=	${SGMLDIR}/${PORTNAME}/${PORTVERSION}
MKCATALOG=	${PREFIX}/sbin/mkcatalog

do-install:
	@[ -d ${INSTDIR} ] || ${MKDIR} ${INSTDIR}
	@${INSTALL_MAN} ${WRKSRC}/*.dtd ${INSTDIR}
	@${INSTALL_MAN} ${WRKSRC}/*.ent ${INSTDIR}
	@${SED} -e 's!%%INSTDIR%%!${INSTDIR}!' ${FILESDIR}/catalog \
	  > ${INSTDIR}/catalog

post-install:
	@${MKCATALOG} -q install ${PORTNAME}/${PORTVERSION}

.include <bsd.port.mk>
