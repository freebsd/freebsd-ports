# New ports collection makefile for:	DocBook XML for ScrollKeeper
# Date created:		16 January 2003
# Whom:			marcus@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	docbook-sk
PORTVERSION=	4.1.2
CATEGORIES=	textproc
MASTER_SITES=	http://www.docbook.org/xml/${PORTVERSION}/ \
		http://www.oasis-open.org/committees/docbook/xml/${PORTVERSION}/
DISTNAME=	docbkx${PORTVERSION:S/.//g}

MAINTAINER=	gnome@FreeBSD.org

USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PLIST_SUB=	DTD_VERSION=${PORTVERSION}

DOCBOOKDIR=	${PREFIX}/share/sk/${PORTNAME:S/-sk//}/${PORTVERSION}

pre-install:
	@[ -d ${DOCBOOKDIR}/ent ] || ${MKDIR} ${DOCBOOKDIR}/ent

do-install:
	for file in `unzip -l ${DISTDIR}/${DISTFILES}|${AWK} '/:[0-9].*[^\/]$$/{print $$4}'`; do \
		${INSTALL_DATA} ${WRKSRC}/$$file ${DOCBOOKDIR}/$$file; \
	done

.include <bsd.port.mk>
