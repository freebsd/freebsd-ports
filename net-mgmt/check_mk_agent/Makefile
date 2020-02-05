# $FreeBSD$

PORTNAME=	check_mk_agent
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.0p8
CATEGORIES=	net-mgmt
MASTER_SITES=	https://raw.githubusercontent.com/tribe29/checkmk/${DISTVERSIONFULL}/agents/:agent \
		https://raw.githubusercontent.com/tribe29/checkmk/${DISTVERSIONFULL}/doc/agents/:doc \
		https://raw.githubusercontent.com/tribe29/checkmk/${DISTVERSIONFULL}/:license
DISTFILES=	${_CHECKMK_AGENT}:agent \
		README.FreeBSD:doc \
		COPYING:license
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Nagios-compatible agent for the Check_MK monitoring

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	bash>0:shells/bash

USES=		perl5 shebangfix
USE_PERL5=	run

SHEBANG_FILES=	${_CHECKMK_AGENT}

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=	# none
EXTRACT_AFTER_ARGS=	${WRKSRC}

NO_ARCH=	yes
NO_BUILD=	yes
NO_TEST=	yes

SUB_FILES=	pkg-message
SUB_LIST=	PORTNAME=${PORTNAME}

NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/${PORTNAME}

PORTDOCS=	README.FreeBSD

OPTIONS_DEFINE=	DOCS

_CHECKMK_AGENT=		${PORTNAME}.freebsd
_CHECKMK_CONFDIR=	${LOCALBASE}/etc/check_mk
_CHECKMK_LIBDIR=	${LOCALBASE}/lib/check_mk_agent
_CHECKMK_TMPDIR=	/var/run/check_mk

post-patch:
	@${REINPLACE_CMD} \
		-e 's|%%CHECKMK_LIBDIR%%|${_CHECKMK_LIBDIR}|' \
		-e 's|%%CHECKMK_CONFDIR%%|${_CHECKMK_CONFDIR}|' \
		-e 's|%%CHECKMK_TMPDIR%%|${_CHECKMK_TMPDIR}|' \
		-e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		-e 's|%%BASH%%|${LOCALBASE}/bin/bash|' \
		${WRKSRC}/${_CHECKMK_AGENT}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${_CHECKMK_AGENT} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.FreeBSD \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
