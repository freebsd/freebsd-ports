# New ports collection makefile for:	"Simplified" DocBook XML DTD
# Date created:		25 December 2000
# Whom:			KIRIYAMA Kazuhiko <kiri@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sdocbook-xml
PORTVERSION= 	4.1.2.4
CATEGORIES=	textproc
MASTER_SITES=	http://nwalsh.com/docbook/simple/4.1.2.4/
DISTNAME=	sdb${PORTVERSION:S/.//g}

MAINTAINER=	kiri@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/share/xml/docbook/readme.txt:${PORTSDIR}/textproc/docbook-xml

USE_ZIP=	yes
NO_MTREE=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}

INSTDIR=	${PREFIX}/share/xml/docbook
DTDDIR=		${INSTDIR}/sdocbook
ENTDIR=		${INSTDIR}/sdocbook/ent

do-install:
	${MKDIR} ${ENTDIR}
	${INSTALL_DATA} ${FILESDIR}/catalog ${DTDDIR}
	cd ${WRKSRC}; \
		${INSTALL_DATA} COPYRIGHT ChangeLog LostLog README VERSION \
			*.dtd *.mod *.css *.xml ${DTDDIR}; \
		${INSTALL_DATA} ent/* ${ENTDIR}
	if [ ! -f ${INSTDIR}/catalog ]; then \
		${ECHO} "CATALOG \"sdocbook/catalog\"" > ${INSTDIR}/catalog; \
	else \
		${SETENV} LANG=C ${PERL} -ni -e 'print if !m|sdocbook/catalog|;print "CATALOG \"sdocbook/catalog\"\n" if eof;' ${INSTDIR}/catalog; \
	fi

.include <bsd.port.mk>
