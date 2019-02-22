# $FreeBSD$

PORTNAME=	check_mk_agent
DISTVERSION=	1.5.0p12
CATEGORIES=	net-mgmt
MASTER_SITES=	https://mathias-kettner.de/support/${DISTVERSION}/
DISTNAME=	check-mk-raw-${DISTVERSION}.cre

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Nagios-compatible agent for the Check_MK monitoring

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	bash>0:shells/bash

USES=	shebangfix

SHEBANG_FILES=	agents/${PORTNAME}.freebsd

NO_ARCH=	yes
NO_BUILD=	yes
NO_TEST=	yes

PLIST_FILES=	bin/${PORTNAME}
SUB_FILES=	pkg-message
SUB_LIST=	PORTNAME=${PORTNAME}

PORTDOCS=	README.FreeBSD

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -E -e 's|^(export MK_CONFDIR=")|\1${PREFIX}|' \
		-e 's|/usr/local/bin/bash|${LOCALBASE}/bin/bash|g' \
		${WRKSRC}/agents/${PORTNAME}.freebsd

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/agents/${PORTNAME}.freebsd ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/agents/README.FreeBSD ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
