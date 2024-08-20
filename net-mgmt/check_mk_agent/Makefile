PORTNAME=	check_mk_agent
DISTVERSIONPREFIX=	v
DISTVERSION=	2.3.0p12
CATEGORIES=	net-mgmt
MASTER_SITES=	https://raw.githubusercontent.com/Checkmk/checkmk/${DISTVERSIONFULL}/agents/:agent \
		https://raw.githubusercontent.com/Checkmk/checkmk/${DISTVERSIONFULL}/doc/agents/:doc \
		https://raw.githubusercontent.com/Checkmk/checkmk/${DISTVERSIONFULL}/:license
DISTFILES=	${_CHECKMK_AGENT}:agent \
		README.FreeBSD:doc \
		COPYING:license
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ivalentine@arizona.edu
COMMENT=	Checkmk agent to monitor *nix style systems
WWW=		https://checkmk.com/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	bash:shells/bash \
		ipmitool:sysutils/ipmitool \
		statgrab:devel/libstatgrab \
		wget:ftp/wget

USES=		perl5 python:3.4+ shebangfix
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
_CHECKMK_LIBDIR=	${PREFIX}/lib/check_mk_agent
_CHECKMK_CONFDIR=	${PREFIX}/etc/check_mk

post-patch:
	@${REINPLACE_CMD} \
		-e 's|%%CHECKMK_LIBDIR%%|${_CHECKMK_LIBDIR}|' \
		-e 's|%%CHECKMK_CONFDIR%%|${_CHECKMK_CONFDIR}|' \
		-e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/${_CHECKMK_AGENT}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${_CHECKMK_AGENT} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.FreeBSD \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
