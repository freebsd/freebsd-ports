# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	google-daemon
PORTVERSION=	1.2.1
PORTREVISION=	0
CATEGORIES=	net

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Google daemon for use with Google Cloud Compute Engine

BUILD_DEPENDS=	python:lang/python
RUN_DEPENDS=	python:lang/python \
		sudo:security/sudo

USES=		python shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	GoogleCloudPlatform
GH_PROJECT=	compute-image-packages
USE_RC_SUBR=	google-accounts-manager
WRKSRC_SUBDIR=	${PORTNAME}

SHEBANG_FILES=	usr/share/google/google_daemon/accounts.py \
		usr/share/google/google_daemon/accounts_manager.py \
		usr/share/google/google_daemon/accounts_manager_daemon.py \
		usr/share/google/google_daemon/address_manager.py \
		usr/share/google/google_daemon/desired_accounts.py \
		usr/share/google/google_daemon/manage_accounts.py \
		usr/share/google/google_daemon/manage_addresses.py \
		usr/share/google/google_daemon/utils.py

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/usr/share/google/google_daemon/accounts.py \
		${WRKSRC}/usr/share/google/google_daemon/accounts_manager.py \
		${WRKSRC}/usr/share/google/google_daemon/utils.py
	@${RM} ${WRKSRC}/usr/share/google/google_daemon/*.bak \
		${WRKSRC}/usr/share/google/google_daemon/*.orig

do-build:
	${PYTHON_CMD} -m compileall ${WRKSRC}/usr/share/google/google_daemon

do-install:
	cd ${WRKSRC}/usr/share ; ${COPYTREE_BIN} google ${STAGEDIR}${PREFIX}/share

.include <bsd.port.mk>
