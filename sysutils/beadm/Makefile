PORTNAME=	beadm
PORTVERSION=	1.3.5
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	GH

MAINTAINER=	vermaden@interia.pl
COMMENT=	Solaris-like utility to manage Boot Environments on ZFS
WWW=		https://github.com/vermaden/beadm/

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	vermaden

NO_ARCH=	yes
NO_BUILD=	yes

CONFLICTS_INSTALL=	beadm-devel

PLIST_FILES=	sbin/${PORTNAME} \
		share/man/man8/${PORTNAME}.8.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/sbin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 \
		${STAGEDIR}${PREFIX}/share/man/man8/

.include <bsd.port.mk>
