# Created by: lev@FreeBSD.org
# $FreeBSD$

PORTNAME=	mod_dav_svn
DISTNAME=	subversion-${PORTVERSION}

CATEGORIES=	www

MAINTAINER=	lev@FreeBSD.org
COMMENT=	Apache module for subversion serving.

.if defined(WITH_SUBVERSION_VER) && ${WITH_SUBVERSION_VER} == 18
MASTERDIR=	${.CURDIR}/../../devel/subversion18
.else
MASTERDIR=	${.CURDIR}/../../devel/subversion
.endif
PKGDIR=		${.CURDIR}

SVN_BUILD_ADDONS=	yes

.include "${MASTERDIR}/Makefile.common"

USE_APACHE=	22+

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
	${INSTALL_DATA} ${WRKDIR}/220_subversion.conf.sample ${STAGEDIR}${PREFIX}/${APACHEETCDIR}/modules.d

.include <bsd.port.post.mk>
