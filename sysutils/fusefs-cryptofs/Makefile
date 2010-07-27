# New ports collection makefile for:	fusefs-cryptofs
# Date created:				2008-05-21
# Whom:					Yen-Ming Lee <leeym@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cryptofs
PORTVERSION=	0.6.0
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	http://reboot78.re.funpic.de/cryptofs/
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A encrypted filesystem for FUSE

BUILD_DEPENDS=	${LOCALBASE}/include/fuse.h:${PORTSDIR}/sysutils/fusefs-libs
LIB_DEPENDS=	gcrypt.17:${PORTSDIR}/security/libgcrypt \
		glib-2.0:${PORTSDIR}/devel/glib20
RUN_DEPENDS=	${LOCALBASE}/modules/fuse.ko:${PORTSDIR}/sysutils/fusefs-kmod

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnometarget

PLIST_FILES=	bin/cryptofs

.if !defined(NOPORTDOCS)
PORTDOCS=	README cryptofs.conf
post-install:
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
