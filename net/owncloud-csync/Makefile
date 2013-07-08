# Created by: arrowdodger <6yearold@gmail.com>
# $FreeBSD$

PORTNAME=	owncloud-csync
PORTVERSION=	0.70.7
CATEGORIES=	net kde
MASTER_SITES=	http://download.owncloud.com/download/
DISTNAME=	ocsync-${PORTVERSION}

MAINTAINER=	6yearold@gmail.com
COMMENT=	A csync fork for Owncloud

LICENSE=	GPLv2

LIB_DEPENDS=	iconv:${PORTSDIR}/converters/libiconv \
		iniparser:${PORTSDIR}/devel/iniparser \
		smbclient:${PORTSDIR}/net/samba-libsmbclient \
		ssh:${PORTSDIR}/security/libssh \
		neon:${PORTSDIR}/www/neon29

USES=	cmake:outsource
USE_BZIP2=	yes
USE_PKGCONFIG=	build
USE_SQLITE=	yes
CMAKE_ARGS+=	-DWITH_LOG4C=NO \
		-DMAN_INSTALL_DIR=${MANPREFIX}/man

MAN1=		ocsync.1

USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

DOCSDIR=	/usr/local/share/doc/ocsync
ETCDIR=		/usr/local/etc/ocsync

.include <bsd.port.mk>
