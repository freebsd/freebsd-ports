PORTNAME=	beadm
PORTVERSION=	1.2.99.20180708
PORTREVISION=	3
CATEGORIES=	sysutils
PKGNAMESUFFIX=	-devel
MASTER_SITES=	\
		LOCAL/bdrewery/${PORTNAME} \
		http://mirror.shatow.net/freebsd/${PORTNAME}/ \
		GH

MAINTAINER=	vermaden@interia.pl
COMMENT=	Solaris-like utility to manage Boot Environments on ZFS
WWW=		https://github.com/vermaden/beadm/

LICENSE=	BSD2CLAUSE

DEPRECATED=	Outdated development port. Use sysutils/beadm instead.
EXPIRATION_DATE=2024-08-15

USE_GITHUB=	yes
GH_ACCOUNT=	vermaden
GH_TAGNAME=	2665f52786a12aadbe8984731b8a64d1249692f4

NO_BUILD=	YES

CONFLICTS_INSTALL=	beadm

PLIST_FILES=	sbin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} \
	    ${STAGEDIR}${PREFIX}/sbin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 \
	  ${STAGEDIR}${PREFIX}/share/man/man1/

.include <bsd.port.mk>
