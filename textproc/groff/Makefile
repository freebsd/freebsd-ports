# Created by: Ulrich Spoerlein <uqs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	groff
PORTVERSION=	1.22.4
CATEGORIES=	textproc
MASTER_SITES=	GNU

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Software typesetting package

LICENSE=	GPLv3

BUILD_DEPENDS=	gsfonts>=0:print/gsfonts \
		psselect:print/psutils
RUN_DEPENDS:=	psselect:print/psutils

MAKE_JOBS_UNSAFE=	yes

USES=		cpe ghostscript gmake perl5 shebangfix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-awk=/usr/bin/awk
CONFIGURE_ENV+=	PERLPATH=${perl_CMD} # shebangfix

CPE_VENDOR=	gnu
SHEBANG_FILES=	src/utils/afmtodit/afmtodit.pl \
		contrib/mm/mmroff.pl \
		font/devps/generate/symbol.sed
SHEBANG_LANG=	sed
sed_OLD_CMD=	/bin/sed
sed_CMD=	/usr/bin/sed

# Canonicalize to A4 if set.
.if defined(A4) || (defined(PAPERSIZE) && ${PAPERSIZE:tu} == "A4")
PAPERSIZE=A4
.endif
.if defined(PAPERSIZE)
CONFIGURE_ENV+=	PAGE=${PAPERSIZE}
.endif

OPTIONS_DEFINE=	X11
X11_DESC=	X11 devices (-TX*) and gxditview
OPTIONS_DEFAULT=	X11

CONFLICTS=	ja-groff-[0-9]*

INFO=	groff

DATADIR=	${PREFIX}/share/${PORTNAME}/${PORTVERSION}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}
EXAMPLESDIR=	${DOCSDIR}/examples

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MX11}
CONFIGURE_ARGS+=--without-x
PLIST_SUB+=	X11="@comment "
.if exists(${LOCALBASE}/bin/pnmcut) && exists(${LOCALBASE}/bin/pnmcrop) && \
    exists(${LOCALBASE}/bin/pnmtops) && exists(${LOCALBASE}/bin/pnmtopng)
PLIST_SUB+=	HTMLDOCS=""
.else
PLIST_SUB+=	HTMLDOCS="@comment "
.endif
.else
USE_XORG=	x11 xaw xmu
BUILD_DEPENDS+=	${LOCALBASE}/bin/pnmtops:graphics/netpbm
RUN_DEPENDS+=	${LOCALBASE}/bin/pnmtops:graphics/netpbm
CONFIGURE_ARGS+=--with-x --with-appresdir=${PREFIX}/lib/X11/app-defaults
PLIST_SUB+=	X11=""
PLIST_SUB+=	HTMLDOCS=""
.endif

post-install:
	${INSTALL_DATA} ${FILESDIR}/mdoc.local ${STAGEDIR}/${PREFIX}/share/groff/site-tmac

.include <bsd.port.mk>
