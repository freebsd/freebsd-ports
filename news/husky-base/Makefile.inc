#
# $Id$
#

PKGNAMEPREFIX=	husky-
DIST_SUBDIR=	husky

WRKSRC?=	${WRKDIR}/${PORTNAME}
ONLY_FOR_ARCHS=	i386

.if ${PORTNAME} != "base"
BUILD_DEPENDS=	${LOCALBASE}/etc/fido/huskymak.cfg:${PORTSDIR}/news/husky-base

USE_GMAKE=	yes

MAKE_ARGS+=	PREFIX="${PREFIX}" LOCALBASE="${LOCALBASE}" \
		CC="${CC}" CXX="${CXX}" GPP="${CXX}" MKSHARED="${CC}" \
		OPTCFLAGS="-c ${CFLAGS}" WARNFLAGS=""

pre-build:
	@${LN} -sf ${LOCALBASE}/etc/fido/huskymak.cfg ${WRKDIR}
.endif
