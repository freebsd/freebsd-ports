# New ports collection makefile for:	alignmargins
# Date created:		2005-01-28
# Whom:			Michael Nottebrock <lofi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	alignmargins
PORTVERSION=	1.0
CATEGORIES=	print
MASTER_SITES=	http://people.freebsd.org/~lofi/ \
		http://www.linuxprinting.org/download/printing/
DISTFILES=	alignmargins align.ps

MAINTAINER=	lofi@FreeBSD.org
COMMENT=	Utility script to generate custom margins in PPDs for CUPS

NO_BUILD=	yes
USE_PERL=	yes
USE_REINPLACE=	yes

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@${MKDIR} ${WRKSRC}
	@for distfile in ${EXTRACT_ONLY}; do \
		if ! (cd ${WRKDIR} && ${CP} ${_DISTDIR}/$$distfile ${WRKSRC});\
		then \
			exit 1; \
		fi \
	done

post-patch:
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
			-e 's|%%DATADIR%%|${DATADIR}|g' \
		${WRKSRC}/alignmargins

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/alignmargins ${LOCALBASE}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/align.ps ${DATADIR}

.include <bsd.port.mk>
