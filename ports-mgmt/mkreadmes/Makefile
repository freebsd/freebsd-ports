PORTNAME=	mkreadmes
DISTVERSION=	1.3
CATEGORIES=	ports-mgmt
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Speedy substitute for "make readmes"

USES=		tar:bzip2

PLIST_FILES=	man/man1/mkreadmes.1.gz sbin/${PORTNAME}
PORTDATA=	*

post-patch:
	${REINPLACE_CMD} -e 's|-o root -g wheel||g' ${WRKSRC}/Makefile

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
