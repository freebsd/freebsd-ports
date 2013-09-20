# Created by: Conrad J. Sabatier <conrads@cox.net>
# $FreeBSD$

PORTNAME=	mkreadmes
DISTVERSION=	1.3
CATEGORIES=	ports-mgmt
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	conrads@cox.net
COMMENT=	A speedy substitute for "make readmes"

USE_BZIP2=	yes
MAN1=		mkreadmes.1
MANCOMPRESSED=	maybe

PLIST_FILES=	sbin/${PORTNAME}
PORTDATA=	*

NO_STAGE=	yes
post-extract:
# adjust definition of PREFIX in mkreadmes.h only if it differs from
# the current setting of ${PREFIX}
	@${EGREP} -q '^#define[[:space:]]+PREFIX[[:space:]]+"${PREFIX}"' \
		${WRKSRC}/mkreadmes.h || \
	${REINPLACE_CMD} -Ee \
	's|^(#define[[:space:]]+PREFIX[[:space:]]+)\"[^"]+\"|\1"${PREFIX}"|' \
		${WRKSRC}/mkreadmes.h

# adjust reference to ${PREFIX} in usage() function's description of
# the "-t pathname" option only if it differs from the current setting
# of ${PREFIX}
	@${EGREP} -q 'default ${PREFIX}' ${WRKSRC}/main.c || \
	${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' ${WRKSRC}/main.c

.include <bsd.port.mk>
