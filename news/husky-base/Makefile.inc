#
# $Id$
#

PKGNAMEPREFIX=	husky-
#MASTER_SITES=	http://www.physcip.uni-stuttgart.de:8080/fidosoft.husky/
MASTER_SITES?=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	husky
DIST_SUBDIR=	husky

WRKSRC?=	${WRKDIR}/${PORTNAME}
ONLY_FOR_ARCHS=	i386

.if ${PORTNAME} != "base"
BUILD_DEPENDS=	${LOCALBASE}/etc/fido/huskymak.cfg:${PORTSDIR}/news/husky-base

USE_GMAKE=	yes

MAKE_ARGS+=	PREFIX="${PREFIX}" \
		CC="${CC}" CXX="${CXX}" GPP="${CXX}" MKSHARED="${CC}" \
		OPTCFLAGS="-c ${CFLAGS}" WARNFLAGS=""

pre-build:
	@${LN} -sf ${LOCALBASE}/etc/fido/huskymak.cfg ${WRKDIR}
.endif
