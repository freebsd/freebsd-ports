# Created by: janos.mohacsi@bsd.hu
# $FreeBSD$

PORTNAME=	ndpmon
PORTVERSION=	1.4.0
PORTREVISION=	6
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-1.4/

MAINTAINER=	pi@FreeBSD.org
COMMENT=	On-link icmpv6 message monitoring and reporting daemon

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		perl5 shebangfix ssl tar:tgz
SHEBANG_FILES=	demopipeprogram.pl.sample
USE_PERL5=	run
USE_GNOME=	libxml2
USE_RC_SUBR=	ndpmonitor

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	OSTYPE=FreeBSD
CONFIGURE_ARGS=	--with-var-datadir=${PREFIX}/var --with-confdir=${ETCDIR} \
		--with-libxml2=${LOCALBASE} --cache-file=/dev/null

PORTDOCS=	INSTALL README
CUSTOMMSG=	${WRKDIR}/custom-message
PKGMESSAGE=	${CUSTOMMSG}

OPTIONS_DEFINE=		DOCS MACRESOLV
OPTIONS_DEFAULT=
OPTIONS_SUB=		yes

MACRESOLV_DESC=			Enable MAC Manufacturer Resolution
MACRESOLV_CONFIGURE_ENABLE=	mac-resolv
MACRESOLV_BUILD_DEPENDS=	p5-libwww>=6.05:www/p5-libwww
MACRESOLV_RUN_DEPENDS=		p5-libwww>=6.05:www/p5-libwww
MACRESOLV_BROKEN=		MACRESOLV option tries to fetch during build

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		-e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/ndpmon.8 \
		${WRKSRC}/create_html_table.py \
		${WRKSRC}/demopipeprogram.pl.sample \
		${WRKSRC}/config_ndpmon.xml.in \
		${WRKSRC}/config_ndpmon.xml
	(cd ${WRKSRC}; ${MAKE} clean)
	${TOUCH} ${CUSTOMMSG}
.if ${PORT_OPTIONS:MMACRESOLV}
	${CAT} ${.CURDIR}/pkg-message.MACRESOLV > ${CUSTOMMSG}
.endif

do-install:
	${INSTALL_MAN} ${WRKSRC}/ndpmon.8 ${STAGEDIR}${PREFIX}/man/man8
	${INSTALL_PROGRAM} ${WRKSRC}/ndpmon ${STAGEDIR}${PREFIX}/sbin

	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.dtd ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/demopipeprogram.pl.sample ${STAGEDIR}${DATADIR}
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

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
