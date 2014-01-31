# Created by: Ulrich Spoerlein <uqs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	groff
PORTVERSION=	1.22.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	groff

MAINTAINER=	uqs@FreeBSD.org
COMMENT=	Software typesetting package

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/bin/psselect:${PORTSDIR}/print/psutils
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_GHOSTSCRIPT= yes
USES=		gmake perl5
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-awk=/usr/bin/awk

# Canonicalize to A4 if set.
.if defined(A4) || (defined(PAPERSIZE) && ${PAPERSIZE:U} == "A4")
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

.include <bsd.port.pre.mk>
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
BUILD_DEPENDS+=	${LOCALBASE}/bin/pnmtops:${PORTSDIR}/graphics/netpbm
RUN_DEPENDS+=	${LOCALBASE}/bin/pnmtops:${PORTSDIR}/graphics/netpbm
CONFIGURE_ARGS+=--with-x --with-appresdir=${PREFIX}/lib/X11/app-defaults
PLIST_SUB+=	X11=""
PLIST_SUB+=	HTMLDOCS=""
.endif

# Run in src/libs/gnulib subdir, too
post-configure:
	@(cd ${WRKSRC}/src/libs/gnulib && \
	    ${SET_LATE_CONFIGURE_ARGS} \
	    if ! ${SETENV} CC="${CC}" CPP="${CPP}" CXX="${CXX}" \
	    CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" \
	    INSTALL="/usr/bin/install -c ${_BINOWNGRP}" \
	    INSTALL_DATA="${INSTALL_DATA}" \
	    INSTALL_LIB="${INSTALL_LIB}" \
	    INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
	    INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
	    ${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}; then \
		 ${ECHO_MSG} "===>  Script \"${CONFIGURE_SCRIPT}\" failed unexpectedly."; \
		 (${ECHO_CMD} ${CONFIGURE_FAIL_MESSAGE}) | ${FMT} 75 79 ; \
		 ${FALSE}; \
	    fi)

post-install:
	${INSTALL_DATA} ${FILESDIR}/mdoc.local ${STAGEDIR}/${PREFIX}/share/groff/site-tmac

.include <bsd.port.post.mk>
