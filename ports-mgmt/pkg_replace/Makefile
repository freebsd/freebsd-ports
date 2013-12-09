# Created by: Securedog <securedog@users.sourceforge.jp>
# $FreeBSD$

PORTNAME=	pkg_replace
PORTVERSION=	0.8.0
PORTREVISION=	6
CATEGORIES=	ports-mgmt
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	portutil/22116

PATCH_SITES=	http://member.tokoha-u.ac.jp/~kdeguchi/download/
PATCHFILES=	${PKGNAME}.patch

MAINTAINER=	kdeguchi@sz.tokoha-u.ac.jp
COMMENT=	Utility for upgrading installed packages

USE_BZIP2=	yes
MAKE_ARGS=	PREFIX="${PREFIX}" \
		PORTSDIR="${PORTSDIR}" PKG_DBDIR="${PKG_DBDIR}"

OPTIONS_DEFINE=	ZSH

.if empty(WITH_PKGNG)
OPTIONS_DEFINE+=	PKGDB_FIX
PKGDB_FIX_DESC=	Fixing tool of installed package dependencies
.else
PLIST_SUB+=	PKGDB_FIX="@comment "
.endif

OPTIONS_SUB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's/pkg_replace/pkg_replace pkgdb_fix/' ${WRKSRC}/sbin/Makefile
	@${REINPLACE_CMD} -e 's/mkdir -p $${FILESDIR}/@true/' ${WRKSRC}/share/zsh/Makefile

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions

.include <bsd.port.mk>
