PORTNAME=	rc-subr-jail
PORTVERSION=	5
CATEGORIES=	ports-mgmt
MASTER_SITES=	#
DISTFILES=	#
EXTRACT_ONLY=	#

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Shell library to help writing RC scripts with jail support
WWW=		https://cgit.freebsd.org/ports/tree/ports-mgmt/rc-subr-jail

LICENSE=	BSD3CLAUSE

NO_ARCH=	yes
NO_BUILD=	yes
NO_MTREE=	yes

PLIST_FILES=	share/rc-subr-jail/rc.subr.jail

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${PATCHDIR}/rc.subr.jail ${STAGEDIR}${DATADIR}/rc.subr.jail

.include <bsd.port.mk>
