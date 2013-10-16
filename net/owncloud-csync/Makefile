# Created by: arrowdodger <6yearold@gmail.com>
# $FreeBSD$

PORTNAME=	owncloud-csync
PORTVERSION=	0.90.2
CATEGORIES=	net kde
MASTER_SITES=	http://download.owncloud.com/download/
DISTNAME=	ocsync-${PORTVERSION}

MAINTAINER=	6yearold@gmail.com
COMMENT=	csync fork for Owncloud

LICENSE=	GPLv2

LIB_DEPENDS=	libiniparser.so:${PORTSDIR}/devel/iniparser \
		libsmbclient.so:${PORTSDIR}/net/samba-libsmbclient \
		libssh.so.4.2.2:${PORTSDIR}/security/libssh \
		libneon.so:${PORTSDIR}/www/neon29

USES=		cmake:outsource iconv pkgconfig
USE_BZIP2=	yes
USE_SQLITE=	yes
CMAKE_ARGS+=	-DUNIT_TESTING=NO \
		-DMAN_INSTALL_DIR=${MANPREFIX}/man

USE_LDCONFIG=	yes

DOCSDIR=	${LOCALBASE}/share/doc/ocsync
ETCDIR=		${LOCALBASE}/etc/ocsync

.include <bsd.port.mk>
