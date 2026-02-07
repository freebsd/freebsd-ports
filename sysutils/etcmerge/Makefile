PORTNAME=	etcmerge
PORTVERSION=	0.4
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Automatic 3-way merge of /etc updates
WWW=		https://BSDforge.com/projects/sysutils/etcmerge/

LICENSE=	NONE

NO_BUILD=	yes
NO_ARCH=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	share/man/man8/${PORTNAME}.8.gz sbin/etcmerge

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/sbin/${PORTNAME}
	${INSTALL_MAN} ${FILESDIR}/${PORTNAME}.8 ${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>
