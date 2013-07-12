#
# $Id$
#

PKGNAMEPREFIX=	husky-
DIST_SUBDIR=	husky

WRKSRC?=	${WRKDIR}/${PORTNAME}

.if ${PORTNAME} != "base"
BUILD_DEPENDS=	${LOCALBASE}/etc/fido/huskymak.cfg:${PORTSDIR}/news/husky-base

USES+=		gmake

MAKE_ARGS+=	PREFIX="${PREFIX}" LOCALBASE="${LOCALBASE}" \
		CC="${CC}" CXX="${CXX}" GPP="${CXX}" MKSHARED="${CC}" \
		OPTCFLAGS="-c ${CFLAGS}" WARNFLAGS=""

pre-build:
	@${LN} -sf ${LOCALBASE}/etc/fido/huskymak.cfg ${WRKDIR}
.endif
