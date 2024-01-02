PORTNAME=	aoe
PORTVERSION=	1.2.0
PORTREVISION=	5
CATEGORIES=	net
MASTER_SITES=	https://people.freebsd.org/~sson/aoe/
DISTNAME=	${PORTNAME}-freebsd-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FreeBSD driver for ATA over Ethernet (AoE)
WWW=		https://web.archive.org/web/20120420082041/http://www.coraid.com/support/freebsd/

LICENSE=	BSD2CLAUSE

BROKEN_armv6=		fails to compile: implicit declaration of function 'cp15_pmccntr_get' is invalid in C99
BROKEN_FreeBSD_13=	crashes dereferencing vnet_entry_ifnet
BROKEN_FreeBSD_14=	crashes dereferencing vnet_entry_ifnet

USES=	kmod uidfix
USE_RC_SUBR=	aoe

WRKSRC=		${WRKDIR}/dev/aoe

PLIST_FILES=	share/man/man4/aoe.4.gz \
		${KMODDIR}/aoe.ko

post-install:
	${INSTALL_MAN} ${WRKDIR}/aoe.4 ${STAGEDIR}${PREFIX}/share/man/man4/

.include <bsd.port.mk>
