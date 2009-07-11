# New ports collection makefile for:	execwrap
# Date created:		22 June 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	execwrap
PORTVERSION=	0.5
CATEGORIES=	security
MASTER_SITES=	http://freebsd.unixfreunde.de/sources/
DISTNAME=	ExecWrap-${DISTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Super-user exec wrapper

NO_WRKSUBDIR=	yes
PORTDOCS=	README
PLIST_FILES=	bin/${PORTNAME}
EXECWRAP_VARS=	PARENT_UID TARGET_MIN_UID TARGET_MIN_GID \
		TARGET_PATH_PREFIX DEFAULT_UID DEFAULT_GID
EXECWRAP_TARGET_PATH_PREFIX?=	"${WWWDIR:S|/${PORTNAME}$||}"
.for _var in ${EXECWRAP_VARS}
.	ifdef EXECWRAP_${_var}
_SED_LINE+=	s|${_var}.*|${_var} ${EXECWRAP_${_var}}|;
.	endif
.endfor

post-patch:
	@${REINPLACE_CMD} -e '${_SED_LINE}' ${WRKSRC}/execwrap_config.h

pre-build:
	@${ECHO_CMD} "============================================"
	@${ECHO_CMD} "You can use the following variables to tweak"
	@${ECHO_CMD} "compile-time options:"
	@for opt in ${EXECWRAP_VARS:S|^|EXECWRAP_|};do ${ECHO_MSG} "  $$opt";done
	@${ECHO_CMD} "============================================"

do-build:
	@cd ${WRKSRC}/ && ${CC} ${CFLAGS} -o ${PORTNAME} ${PORTNAME}.c

do-install:
	@${INSTALL_PROGRAM} -m 4511 ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
.ifndef NOPORTDOCS
	@${INSTALL} -d ${DOCSDIR}/
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
