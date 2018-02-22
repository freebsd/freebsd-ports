# Created by: Autrijus Tang <autrijus@autrijus.org>
# $FreeBSD$

PKGNAMESUFFIX=	-kwallet
PORTREVISION=	2
CATEGORIES=	security kde

MAINTAINER=	lev@FreeBSD.org
COMMENT=	KDE KWallet integration for Version control system

.if defined(WITH_SUBVERSION_VER) && ${WITH_SUBVERSION_VER} == 18
PORTREVISION=	2
MASTERDIR=	${.CURDIR}/../../devel/subversion18
.else
MASTERDIR=	${.CURDIR}/../../devel/subversion
.endif
PKGDIR=		${.CURDIR}

SVN_BUILD_ADDONS=	yes

USE_KDE=		kdelibs runtime
USES+=			kde:4

.include "${MASTERDIR}/Makefile.common"

CONFIGURE_ARGS+=	--with-kwallet=${KDE_PREFIX}

ALL_TARGET=	kwallet-lib
INSTALL_TARGET=	install-kwallet-lib

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so

.include <bsd.port.post.mk>
