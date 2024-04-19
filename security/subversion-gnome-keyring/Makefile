PKGNAMESUFFIX=	-gnome-keyring
CATEGORIES=	security gnome

MAINTAINER=	michaelo@apache.org
COMMENT=	Gnome Keyring integration for Version control system
WWW=		https://subversion.apache.org/

PORTREVISION_LATEST=	2
PORTREVISION_LTS=		2

.include "${.CURDIR}/../../devel/subversion/Makefile.addons"

LIB_DEPENDS+=	libsecret-1.so:security/libsecret

CONFIGURE_ARGS+=	--with-gnome-keyring

ALL_TARGET=	gnome-keyring-lib
INSTALL_TARGET=	install-gnome-keyring-lib

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so

.include <bsd.port.post.mk>
