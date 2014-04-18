# Created by: Kris Moore <kris@pcbsd.org>
# $FreeBSD: $

PORTNAME=	preload
PORTVERSION=	0.6.4
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	kris@pcbsd.org
COMMENT=	Adaptive readahead daemon

LICENSE=	GPLv2

BUILD_DEPENDS=	help2man:${PORTSDIR}/misc/help2man \
		gsed:${PORTSDIR}/textproc/gsed

GNU_CONFIGURE=	yes
CONFIG_ARGS=+
USE_RC_SUBR=	preload
USES=		pkgconfig
USE_GNOME=	glib20

PLIST_FILES=	sbin/preload man/man8/preload.8.gz etc/preload.conf.dist
MAN8=		preload.8.gz

do-install:
	@cd ${WRKSRC}/src && ./gen.preload.conf.sh preload.conf.in confkeys.h > preload.conf
	${INSTALL_PROGRAM} ${WRKSRC}/src/preload ${STAGEDIR}${PREFIX}/sbin/
	${INSTALL_DATA} ${WRKSRC}/src/preload.conf ${STAGEDIR}${PREFIX}/etc/preload.conf.dist
	${INSTALL_MAN} ${WRKSRC}/src/preload.8 ${STAGEDIR}${PREFIX}/man/man8/

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
