# Created by: janos.mohacsi@bsd.hu
# $FreeBSD$

PORTNAME=	ndpmon
PORTVERSION=	1.4.0
PORTREVISION=	5
CATEGORIES=	net-mgmt ipv6
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-1.4/

MAINTAINER=	pi@FreeBSD.org
COMMENT=	On-link icmpv6 message monitoring and reporting daemon

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=		PY4SUITE MACRESOLV
OPTIONS_DEFAULT=

PY4SUITE_DESC=		Depend on py-4suite-xml (for generating HTML)
MACRESOLV_DESC=		Enable MAC Manufacturer Resolution (use p5-libwww)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPY4SUITE}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/Ft/Xml/Domlette.py:textproc/py-4suite-xml
USES+=		python
PLIST_SUB+=	PY=""
.else
PLIST_SUB+=	PY="@comment "
.endif

USES=		perl5 shebangfix tar:tgz
SHEBANG_FILES=	demopipeprogram.pl.sample
USE_PERL5=	run
USE_GNOME=	libxml2
USE_RC_SUBR=	ndpmonitor

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	OSTYPE=FreeBSD
CONFIGURE_ARGS=	--with-var-datadir=${PREFIX}/var --with-confdir=${ETCDIR} \
		--with-libxml2=${LOCALBASE} --cache-file=/dev/null

PORTDOCS=	INSTALL README

.if ${PORT_OPTIONS:MMACRESOLV}
CONFIGURE_ARGS+=--enable-mac-resolv
BUILD_DEPENDS+=	p5-libwww>=6.05:www/p5-libwww
RUN_DEPENDS+=	p5-libwww>=6.05:www/p5-libwww
PLIST_SUB+=	MACRESOLV=""
.else
PLIST_SUB+=	MACRESOLV="@comment "
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
	${INSTALL_MAN} ${WRKSRC}/ndpmon.8 ${STAGEDIR}${PREFIX}/man/man8
	${INSTALL_PROGRAM} ${WRKSRC}/ndpmon ${STAGEDIR}${PREFIX}/sbin

	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.dtd ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/demopipeprogram.pl.sample ${STAGEDIR}${DATADIR}
.if ${PORT_OPTIONS:MPY4SUITE}
	${INSTALL_SCRIPT} ${WRKSRC}/create_html_table.py ${STAGEDIR}${DATADIR}
.endif
.if ${PORT_OPTIONS:MMACRESOLV}
	${MKDIR} ${STAGEDIR}${DATADIR}/plugins/mac_resolv
	${INSTALL_SCRIPT} ${WRKSRC}/plugins/mac_resolv/make-manuf ${STAGEDIR}${DATADIR}/plugins/mac_resolv
	${INSTALL_DATA} ${WRKSRC}/plugins/mac_resolv/*.tmpl ${STAGEDIR}${DATADIR}/plugins/mac_resolv
	${INSTALL_DATA} ${WRKSRC}/plugins/mac_resolv/manuf ${STAGEDIR}${DATADIR}/plugins/mac_resolv
.endif

	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/config_ndpmon.xml ${STAGEDIR}${ETCDIR}/config_ndpmon.xml-dist

	${MKDIR} ${STAGEDIR}${PREFIX}/var/ndpmon
	${INSTALL_DATA} ${WRKSRC}/neighbor_list.xml ${STAGEDIR}${PREFIX}/var/ndpmon/neighbor_list.xml

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MMACRESOLV}
	@${CAT} ${PKGMESSAGE}.MACRESOLV
.endif

.include <bsd.port.mk>
