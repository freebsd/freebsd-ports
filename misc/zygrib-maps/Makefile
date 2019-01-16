# $FreeBSD$

PORTNAME=	zygrib-maps
DISTVERSION=	2.4
PORTREVISION=	1
MASTER_SITES=	http://www.zygrib.org/getfile.php?file=
CATEGORIES=	misc
DISTNAME=	zyGrib_maps${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	High resolution maps for zyGrib

LICENSE=	GPLv3

FETCH_DEPENDS=	curl:ftp/curl
RUN_DEPENDS=	zygrib>0:misc/zygrib

USES=		tar:tgz
NO_BUILD=	yes
NO_ARCH=	yes

DATADIR=	${PREFIX}/share/zygrib

local-makesum: # Workaround: the generic 'make makesum' is broken when custom do-fetch is defined: it calls ${SCRIPTSDIR}/do-fetch.sh.
	@${MAKE} distclean fetch makesum

do-fetch: # fetch needs cookies
	@if [ "${FORCE_FETCH_ALL}" = "true" ] || ! [ -f "${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}" ]; then \
		${LOCALBASE}/bin/curl -fLC - \
			--cookie nada -o /dev/null "${MASTER_SITES}${DISTNAME}${EXTRACT_SUFX}" \
			--next \
			--cookie nada --retry-delay 3 -o "${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}" "${MASTER_SITES}${DISTNAME}${EXTRACT_SUFX}"; \
	fi

do-install:
	cd ${WRKDIR}/data/maps/gshhs && ${COPYTREE_SHARE} '*' ${STAGEDIR}${DATADIR}/maps/gshhs
	@${RM} ${STAGEDIR}${DATADIR}/maps/gshhs/README.*

.include <bsd.port.mk>
