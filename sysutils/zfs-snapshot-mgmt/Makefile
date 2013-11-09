# Created by: Marcin Simonides <marcin@studio4plus.com>
# $FreeBSD$

PORTNAME=	zfs-snapshot-mgmt
PORTVERSION=	20090201
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://marcin.studio4plus.com/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Automatic ZFS snapshot management tool

USE_RUBY=	yes
RUBY_NO_BUILD_DEPENDS=	yes
RUBY_SHEBANG_FILES=	zfs-snapshot-mgmt

NO_BUILD=	yes
MAN8=		zfs-snapshot-mgmt.8

SUB_FILES=	pkg-message

post-patch:	.SILENT
	${FIND} ${WRKSRC} -type f -exec ${REINPLACE_CMD} \
		-e 's|/usr/local|${PREFIX}|g' {} +

NO_STAGE=	yes
do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${MANPREFIX}/man/man8
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf.sample ${PREFIX}/etc

post-install:
	@if [ ! -f ${PREFIX}/etc/${PORTNAME}.conf ]; then \
		${CP} -p ${PREFIX}/etc/${PORTNAME}.conf.sample ${PREFIX}/etc/${PORTNAME}.conf ; \
	fi
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
