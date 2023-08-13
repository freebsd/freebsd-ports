PORTNAME=	xe-guest-utilities
PORTVERSION=	6.2.0
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	LOCAL/feld
DISTNAME=	${PORTNAME}-6.0.2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FreeBSD VM tools for Citrix XenServer and XCP

ONLY_FOR_ARCHS=		amd64 i386
ONLY_FOR_ARCHS_REASON=	requires i386 XEN or amd64 XENHVM kernel
NO_ARCH=	yes
NO_BUILD=	yes

RUN_DEPENDS=	xenstore:${PKGCATEGORY}/xen-guest-tools

USES=		gmake python
USE_RC_SUBR=	xenguest

PLIST_FILES=	sbin/xe-daemon \
		sbin/xe-update-guest-attrs

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/sbin/xe-daemon ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/src/sbin/xe-update-guest-attrs ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
