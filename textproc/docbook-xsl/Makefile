# New ports collection makefile for:   docbook-xml
# Date created:        17 January 2002
# Whom:                des
#
# $FreeBSD$
#

PORTNAME=	docbook-xsl
PORTVERSION=	1.48
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR= docbook

MAINTAINER=	des@freebsd.org

RUN_DEPENDS=	${XMLDIR}/docbook/catalog:${PORTSDIR}/textproc/docbook-xml \
		${XMLDIR}/sdocbook/catalog:${PORTSDIR}/textproc/sdocbook-xml

XMLDIR=		${LOCALBASE}/share/xml
INSTDIR=	${PREFIX}/share/xsl/docbook

NO_BUILD=	yes

post-extract:
	${FIND} ${WRKSRC} -name '.#*' -delete

do-install:
.ifndef NOPORTDOCS
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/doc && ${TAR} -cf - . |\
		${TAR} -xf - -C${DOCSDIR})
	${MKDIR} ${DOCSDIR}/htmlhelp
	(cd ${WRKSRC}/htmlhelp/doc && ${TAR} -cf - . |\
		${TAR} -xf - -C${DOCSDIR}/htmlhelp)
.endif
	${MKDIR} ${INSTDIR}
	(cd ${WRKSRC} && ${TAR} -cf - . --exclude doc --exclude extensions |\
		${TAR} -xf - -C${INSTDIR})

.include <bsd.port.mk>
