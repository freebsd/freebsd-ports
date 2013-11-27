# Created by: Securedog <securedog@users.sourceforge.jp>
# $FreeBSD$

PORTNAME=	pkg_replace
PORTVERSION=	0.8.0
PORTREVISION=	5
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

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's/pkg_replace/pkg_replace pkgdb_fix/' ${WRKSRC}/sbin/Makefile
	@${REINPLACE_CMD} -e 's/mkdir -p $${FILESDIR}/@true/' ${WRKSRC}/share/zsh/Makefile

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sbin/pkg_replace/pkg_replace ${STAGEDIR}${PREFIX}/sbin
	${CP} ${WRKSRC}/etc/pkg_replace.conf ${STAGEDIR}${PREFIX}/etc/pkg_replace.conf.sample
	${INSTALL_MAN} ${WRKSRC}/sbin/pkg_replace/pkg_replace.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
.if ${PORT_OPTIONS:MZSH}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/share/zsh/_pkg_replace ${STAGEDIR}${PREFIX}/share/zsh/site-functions
.endif
.if ${PORT_OPTIONS:MPKGDB_FIX}
	${INSTALL_SCRIPT} ${WRKSRC}/sbin/pkgdb_fix/pkgdb_fix ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/sbin/pkgdb_fix/pkgdb_fix.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
.endif

.include <bsd.port.mk>
