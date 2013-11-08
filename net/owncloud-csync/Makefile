# Created by: arrowdodger <6yearold@gmail.com>
# $FreeBSD$

PORTNAME=	owncloud-csync
PORTVERSION=	0.90.4
CATEGORIES=	net kde
MASTER_SITES=	http://download.owncloud.com/download/
DISTNAME=	ocsync-${PORTVERSION}

MAINTAINER=	6yearold@gmail.com
COMMENT=	Csync fork for Owncloud

LICENSE=	GPLv2

LIB_DEPENDS=	libiniparser.so:${PORTSDIR}/devel/iniparser \
		libsmbclient.so:${PORTSDIR}/net/samba-libsmbclient \
		libssh.so.4:${PORTSDIR}/security/libssh \
		libneon.so:${PORTSDIR}/www/neon29

USES=		cmake:outsource iconv pkgconfig
USE_BZIP2=	yes
USE_SQLITE=	yes
CMAKE_ARGS+=	-DUNIT_TESTING=NO \
		-DMAN_INSTALL_DIR=${MANPREFIX}/man

USE_LDCONFIG=	yes

DOCSDIR=	${PREFIX}/share/doc/ocsync
ETCDIR=		${PREFIX}/etc/ocsync

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	asciidoc:${PORTSDIR}/textproc/asciidoc

post-patch:
	@${REINPLACE_CMD} -e 's/^add_subdirectory(doc)//' ${WRKSRC}/CMakeLists.txt
.endif

.include <bsd.port.mk>
