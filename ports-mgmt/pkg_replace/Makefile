# Created by: Securedog <securedog@users.sourceforge.jp>
# $FreeBSD$

PORTNAME=	pkg_replace
PORTVERSION=	0.8.0
PORTREVISION=	2
CATEGORIES=	ports-mgmt
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=portutil/22116

MAINTAINER=	kdeguchi@sz.tokoha-u.ac.jp
COMMENT=	Utility for upgrading installed packages

USE_BZIP2=	YES
MAKE_ARGS=	PREFIX="${PREFIX}" \
		PORTSDIR="${PORTSDIR}" PKG_DBDIR="${PKG_DBDIR}"

MAN1=		pkg_replace.1
MANCOMPRESSED=	maybe

OPTIONS_DEFINE=		ZSH

.if empty(WITH_PKGNG)
OPTIONS_DEFINE+=	PKGDB_FIX
PKGDB_FIX_DESC=		Fixing tool of installed package dependencies
.else
PLIST_SUB+=	PKGDB_FIX="@comment "
.endif

OPTIONS_SUB=	yes

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPKGDB_FIX}
MAN1+=	pkgdb_fix.1
.endif

post-patch:
.if ${PORT_OPTIONS:MPKGDB_FIX}
	@${REINPLACE_CMD} -e 's/pkg_replace/pkg_replace pkgdb_fix/;' ${WRKSRC}/sbin/Makefile
.endif
.if !${PORT_OPTIONS:MZSH}
	@${REINPLACE_CMD} -e  's/^	sbin \\$$/	sbin/;s/^	share$$//;' ${WRKSRC}/Makefile
.endif

.include <bsd.port.mk>
