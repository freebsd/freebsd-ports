# New ports collection makefile for:	py-keyring
# Date created:				2 September 2009
# Whom:					Douglas Thrift
#
# $FreeBSD$
#

PORTNAME=	keyring
PORTVERSION=	0.1
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP \
		http://code.douglasthrift.net/files/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	Store and access your passwords safely

LATEST_LINK=	py-${PORTNAME}

USE_KDE4=	#
USE_PYTHON=	2.6+
USE_PYDISTUTILS=	yes

OPTIONS=	GNOME_KEYRING "GNOME Keyring backend" Off \
		KDE_KWALLET "KDE KWallet backend" Off

.include <bsd.port.pre.mk>

.if defined(WITH_GNOME_KEYRING)
LIB_DEPENDS+=	gnome-keyring.0:${PORTSDIR}/security/gnome-keyring
PLIST_SUB+=	GNOME_KEYRING=""
.else
PLIST_SUB+=	GNOME_KEYRING="@comment "
.endif

.if defined(WITH_KDE_KWALLET)
PLIST_SUB+=	KDE_KWALLET=""
USE_KDE4+=	kdelibs
.else
PLIST_SUB+=	KDE_KWALLET="@comment "
.endif

post-patch:
.if !defined(WITH_GNOME_KEYRING)
	@${REINPLACE_CMD} -e 's|exts\.append(gnome_keychain_module)|#&|' \
		${WRKSRC}/extensions.py
.endif
.if defined(WITH_KDE_KWALLET)
	@${REINPLACE_CMD} -e 's|kde4-config|${KDE4_PREFIX}/bin/kde4-config|' \
		${WRKSRC}/extensions.py
.else
	@${REINPLACE_CMD} -e 's|exts\.append(kde_kwallet_module)|#&|' \
		${WRKSRC}/extensions.py
.endif

.include <bsd.port.post.mk>
