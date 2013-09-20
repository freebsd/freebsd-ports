# Created by: Yen-Ming Lee <leeym@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cryptofs
PORTVERSION=	0.6.0
PORTREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	http://reboot78.re.funpic.de/cryptofs/
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A encrypted filesystem for FUSE

LIB_DEPENDS=	gcrypt:${PORTSDIR}/security/libgcrypt \
		glib-2.0:${PORTSDIR}/devel/glib20

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USES=		fuse pkgconfig

PLIST_FILES=	bin/cryptofs

.if !defined(NOPORTDOCS)
PORTDOCS=	README cryptofs.conf
NO_STAGE=	yes
post-install:
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
