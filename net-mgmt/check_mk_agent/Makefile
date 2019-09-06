# $FreeBSD$

PORTNAME=	check_mk_agent
DISTVERSION=	1.5.0p21
CATEGORIES=	net-mgmt
MASTER_SITES=	https://mathias-kettner.de/support/${DISTVERSION}/
DISTNAME=	check-mk-raw-${DISTVERSION}.cre

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Nagios-compatible agent for the Check_MK monitoring

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	bash>0:shells/bash

USES=	shebangfix

SHEBANG_FILES=	agents/${CHECKMK_AGENT}

NO_ARCH=	yes
NO_BUILD=	yes
NO_TEST=	yes

PLIST_FILES=	bin/${PORTNAME}
SUB_FILES=	pkg-message
SUB_LIST=	PORTNAME=${PORTNAME}

PORTDOCS=	README.FreeBSD

OPTIONS_DEFINE=	DOCS

CHECKMK_AGENT=	${PORTNAME}.freebsd
CHECKMK_LIBDIR=	${LOCALBASE}/lib/check_mk_agent
CHECKMK_CONFDIR=${LOCALBASE}/etc/check_mk
CHECKMK_TMPDIR=	/var/run/check_mk

post-patch:
	@${REINPLACE_CMD} \
		-e 's|%%CHECKMK_LIBDIR%%|${CHECKMK_LIBDIR}|' \
		-e 's|%%CHECKMK_CONFDIR%%|${CHECKMK_CONFDIR}|' \
		-e 's|%%CHECKMK_TMPDIR%%|${CHECKMK_TMPDIR}|' \
		-e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		-e 's|%%BASH%%|${LOCALBASE}/bin/bash|' \
		${WRKSRC}/agents/${CHECKMK_AGENT}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/agents/${CHECKMK_AGENT} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/agents/README.FreeBSD \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
