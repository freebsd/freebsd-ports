# Created by: Marcin Simonides <marcin@studio4plus.com>
# $FreeBSD$

PORTNAME=	zfs-snapshot-mgmt
PORTVERSION=	20090201
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	http://marcin.studio4plus.com/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Automatic ZFS snapshot management tool

USE_RUBY=	yes
USES=		shebangfix
RUBY_NO_BUILD_DEPENDS=	yes
SHEBANG_FILES=	zfs-snapshot-mgmt

NO_BUILD=	yes
NO_ARCH=	yes

SUB_FILES=	pkg-message

post-patch:	.SILENT
	${FIND} ${WRKSRC} -type f -exec ${REINPLACE_CMD} \
		-e 's|/usr/local|${PREFIX}|g' {} +

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}${MANPREFIX}/man/man8
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf.sample ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
