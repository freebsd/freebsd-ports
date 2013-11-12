# Created by: Oliver Eikemeier
# $FreeBSD$

PORTNAME=	portaudit-db
PORTVERSION=	0.2.3
PORTREVISION=	3
CATEGORIES=	ports-mgmt
DISTFILES=

MAINTAINER=	ports-secteam@FreeBSD.org
COMMENT=	Creates a portaudit database from a current ports tree

RUN_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt

DEPENDS_ARGS+=	WITHOUT_PYTHON=yes

DATABASEDIR?=	${AUDITFILE:H}

PLIST_SUB+=	DATABASEDIR="${DATABASEDIR}"

SED_SCRIPT=	-e 's,%%PREFIX%%,${PREFIX},g' \
		-e "s|%%DATADIR%%|${DATADIR}|g" \
		-e "s|%%LOCALBASE%%|${LOCALBASE}|g" \
		-e "s|%%PORTSDIR%%|${PORTSDIR}|g" \
		-e "s|%%PORTVERSION%%|${PORTVERSION}|g" \
		-e "s|%%DATABASEDIR%%|${DATABASEDIR}|g"

NO_STAGE=	yes
do-build:
	@for f in packaudit.sh packaudit.conf; do \
		${SED} ${SED_SCRIPT} "${FILESDIR}/$$f" > "${WRKDIR}/$$f"; \
	done

do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/packaudit.sh ${PREFIX}/bin/packaudit
	@${INSTALL_DATA} ${WRKDIR}/packaudit.conf ${PREFIX}/etc/packaudit.conf.sample
	@${MKDIR} ${DATADIR}
	@${INSTALL_SCRIPT} ${FILESDIR}/portaudit2vuxml.awk ${DATADIR}
	@${INSTALL_DATA} ${FILESDIR}/vuxml2html.xslt ${FILESDIR}/vuxml2portaudit.xslt ${DATADIR}
	@${MKDIR} ${DATABASEDIR}

.include <bsd.port.mk>
