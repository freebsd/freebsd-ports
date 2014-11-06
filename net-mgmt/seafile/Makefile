# $FreeBSD$

PORTNAME=	seafile
PORTVERSION=	3.1.4
CATEGORIES=	net-mgmt devel

MAINTAINER=	yan_jingfeng@yahoo.com
COMMENT=	Framework for writing networked applications

LICENSE=	GPLv3

BUILD_DEPENDS=	valac:${PORTSDIR}/lang/vala
LIB_DEPENDS=	libsearpc.so:${PORTSDIR}/devel/libsearpc \
		libevhtp.so:${PORTSDIR}/www/libevhtp \
		libzdb.so:${PORTSDIR}/databases/libzdb \
		libcrypto.so:${PORTSDIR}/security/openssl \
		libarchive.so.13:${PORTSDIR}/archivers/libarchive \
		libfuse.so:${PORTSDIR}/sysutils/fusefs-libs \
		libinotify.so:${PORTSDIR}/devel/libinotify \
		libccnet.so:${PORTSDIR}/net-mgmt/ccnet
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}eggtestinfo>0:${PORTSDIR}/devel/py-eggtestinfo \
		${PYTHON_SITELIBDIR}/PIL/__init__.py:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3 \
		bash:${PORTSDIR}/shells/bash

USE_GITHUB=	yes
GH_ACCOUNT=	haiwen
GH_TAGNAME=	v3.1.4
GH_COMMIT=	ac58109

USES=		autoreconf iconv libtool pathfix pkgconfig python:2 shebangfix
GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
USE_LDCONFIG=	yes

WITH_OPENSSL_PORT=	yes
PATHFIX_MAKEFILEIN=	Makefile.am

CONFIGURE_ARGS=	--enable-server
INSTALL_TARGET=	install-strip
WWWDIR=		${PREFIX}/www/haiwen/seafile-server
SEABIN=		${STAGEDIR}${WWWDIR}/seafile/bin
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAKE_JOBS_UNSAFE=	yes

post-install:
	@${MKDIR} ${SEABIN} \
		${STAGEDIR}${WWWDIR}/seafile/share/doc/seafile \
		${STAGEDIR}${WWWDIR}/upgrade
.for SERVPROG in fileserver seaf-fsck seafserv-gc seaf-fuse seaf-migrate \
	seaf-server seaf-server-init seafile-controller seafserv-tool
	${LN} ${STAGEDIR}${PREFIX}/bin/${SERVPROG} ${SEABIN}
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/*.[ps][yh] ${STAGEDIR}${WWWDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/upgrade/*.[ps][yh] \
		${STAGEDIR}${WWWDIR}/upgrade
	${INSTALL_DATA} ${WRKSRC}/doc/seafile-tutorial.doc \
		${STAGEDIR}${WWWDIR}/seafile/share/doc/seafile/
	(cd ${WRKSRC}/scripts/upgrade && \
		${COPYTREE_SHARE} sql ${STAGEDIR}${WWWDIR}/upgrade)

.include <bsd.port.mk>
