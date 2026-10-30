PORTNAME=	mod_subversion
DISTNAME=	subversion-${PORTVERSION}
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

CATEGORIES=	www

MAINTAINER=	michaelo@apache.org
COMMENT=	Apache HTTP Server modules for Apache Subversion
WWW=		https://subversion.apache.org/

USES=		apache

PORTREVISION_LATEST=	1
PORTREVISION_LTS=		1

.include "${.CURDIR}/../../devel/subversion/Makefile.addons"

CONFIGURE_ARGS+=	--with-apxs=${APXS} \
			--with-apache-libexecdir \
			--without-gnome-keyring \
			--without-kwallet
SUB_FILES+=	220_subversion.conf.sample

PLIST_SUB+=	SED=${SED}

ALL_TARGET=	apache-mod
INSTALL_TARGET=	install-mods-shared

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEETCDIR}/modules.d
	${INSTALL_DATA} ${WRKDIR}/220_subversion.conf.sample \
		${STAGEDIR}${PREFIX}/${APACHEETCDIR}/modules.d

.include <bsd.port.post.mk>
