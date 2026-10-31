PKGNAMESUFFIX=	-gnome-keyring
CATEGORIES=	security gnome

MAINTAINER=	michaelo@apache.org
COMMENT=	GNOME Keyring credential cache for Apache Subversion
WWW=		https://subversion.apache.org/

USES=		gnome
USE_GNOME=	glib20

PORTREVISION_LATEST=	1
PORTREVISION_LTS=		1

.include "${.CURDIR}/../../devel/subversion/Makefile.addons"

LIB_DEPENDS+=	libsecret-1.so:security/libsecret

CONFIGURE_ARGS+=	--with-gnome-keyring

ALL_TARGET=	gnome-keyring-lib
INSTALL_TARGET=	install-gnome-keyring-lib

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so

.include <bsd.port.post.mk>
