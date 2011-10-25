# New ports collection makefile for:	ndpmon
# Date created:				2006-12-17
# Whom:					janos.mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	ndpmon
PORTVERSION=	1.4.0
PORTREVISION=	1
CATEGORIES=	net-mgmt ipv6
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-1.4/
EXTRACT_SUFX=	.tgz

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	On-link icmpv6 message monitoring and reporting daemon

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS=	PY4SUITE	"Depend on py-4suite-xml (for generating HTML)"	off \
		MACRESOLV	"Enable MAC Manufacturer Resolution" off

.include <bsd.port.options.mk>

.if defined(WITHOUT_PY4SUITE)
PLIST_SUB+=	PY="@comment "
.else
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/Ft/Xml/Domlette.py:${PORTSDIR}/textproc/py-4suite-xml
USE_PYTHON=	2.6+
PLIST_SUB+=	PY=""
.endif

USE_GNOME=	libxml2
USE_PERL5_RUN=	yes
USE_RC_SUBR=	ndpmonitor

MAKE_JOBS_SAFE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	OSTYPE=FreeBSD
CONFIGURE_ARGS=	--with-var-datadir=${PREFIX}/var --with-confdir=${ETCDIR} \
		--with-libxml2=${LOCALBASE} --cache-file=/dev/null

MAN8=		ndpmon.8
PORTDOCS=	INSTALL README

.if defined(WITH_MACRESOLV)
CONFIGURE_ARGS+=--enable-mac-resolv
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		-e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/ndpmon.8 \
		${WRKSRC}/create_html_table.py \
		${WRKSRC}/demopipeprogram.pl.sample \
		${WRKSRC}/config_ndpmon.xml.in \
		${WRKSRC}/config_ndpmon.xml
	(cd ${WRKSRC}; ${MAKE} clean)

do-install:
	${INSTALL_MAN} ${WRKSRC}/ndpmon.8 ${PREFIX}/man/man8
	${INSTALL_PROGRAM} ${WRKSRC}/ndpmon ${PREFIX}/sbin

	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.dtd ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/demopipeprogram.pl.sample ${DATADIR}
.if defined(WITH_PY4SUITE)
	${INSTALL_SCRIPT} ${WRKSRC}/create_html_table.py ${DATADIR}
.endif

	${MKDIR} ${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/config_ndpmon.xml ${ETCDIR}/config_ndpmon.xml-dist

	${MKDIR} ${PREFIX}/var/ndpmon
	${INSTALL_DATA} ${WRKSRC}/neighbor_list.xml ${PREFIX}/var/ndpmon/neighbor_list.xml

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
