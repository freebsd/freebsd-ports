# New ports collection makefile for:	iiimf-gnome-im-switcher
# Date created:		10 Sep 2004
# Whom:			Kuang-che Wu <kcwu@csie.org>
#
# $FreeBSD$
#

PORTNAME=	gnome-im-switcher
PORTVERSION=	${IIIMF_VER:S/_/./g:C/-.*//}
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.openi18n.org/download/im-sdk/src/
PKGNAMEPREFIX=	iiimf-
DISTNAME=	im-sdk-src-${IIIMF_VER}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kcwu@csie.org
COMMENT=	IIIMF gnome input method switcher

USE_X_PREFIX=	yes

IIIMF_VER=	r12_1-svn2002
USE_BZIP2=	yes
USE_REINPLACE=  yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	intltool gconf2 libglade2 libgnomeui \
		gnomepanel gnomeprefix gnomehack
USE_AUTOCONF_VER=	259
USE_AUTOHEADER_VER=	259
USE_AUTOMAKE_VER=	19
WANT_LIBTOOL_VER=	15

AUTOMAKE_ARGS+=		--add-missing
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

WRKSRC=         ${WRKDIR}/${DISTNAME:S/src-//}/gnome-im-switcher
PATCH_WRKSRC=   ${WRKDIR}/${DISTNAME:S/src-//}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 503000
IGNORE=         "It is supported on FreeBSD 5.3 and later"
.endif

.if ${ARCH} != "i386"
IGNORE=	"${ARCH} is not support."
.endif

CFLAGS+=	-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib -L${X11BASE}/lib -lintl ${PTHREAD_LIBS}
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS}"
UPDATE_ARGS+=	ACLOCAL=${ACLOCAL} AUTOMAKE=${AUTOMAKE} \
		AUTOHEADER=${AUTOHEADER} AUTOCONF=${AUTOCONF} \
		LIBTOOL=${LIBTOOL} LIBTOOLIZE=${LIBTOOLIZE} \
		ACLOCAL_DIR="-I ${LOCALBASE}/share/aclocal -I ${ACLOCAL_DIR}"
TLZ_ARGS=	--copy --force
BNB_PATH=	bonobo/server

post-patch:
	${REINPLACE_CMD} -e "s,/usr/lib/im,${LOCALBASE}/lib/im,g" \
		${WRKSRC}/../acfiles/im_common.m4
	${REINPLACE_CMD} -e "/GNOMECC_DATA_DIR/s,/share/,&gnome/,g" \
		${WRKSRC}/configure.in

pre-configure:
	@cd ${WRKSRC}/.. && ${GMAKE} ${UPDATE_ARGS} update-acfiles
	@cd ${WRKSRC} && glib-gettextize ${TLZ_ARGS}
	@cd ${WRKSRC} && intltoolize ${TLZ_ARGS}
	@cd ${WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${LIBTOOLIZE} ${TLZ_ARGS}
	@cd ${WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${ACLOCAL} \
	 -I ../acfiles -I ${LOCALBASE}/share/aclocal -I ${ACLOCAL_DIR}
	@cd ${WRKSRC} && ${REINPLACE_CMD} \
	 -e "s^\$$ac_aux_dir/ltconfig^${LTCONFIG}^g" \
	 -e "/^ltmain=/!s^\$$ac_aux_dir/ltmain.sh^${LIBTOOLFLAGS} ${LTMAIN}^g" \
	 -e '/^LIBTOOL=/s^\$$(top_builddir)/libtool^${LIBTOOL}^g' \
	 ${LIBTOOLFILES}
	@cd ${WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${AUTOHEADER}

post-configure:
	${REINPLACE_CMD} \
	 -e "s,[(]libdir[)]/${BNB_PATH},{exec_prefix}/libdata/${BNB_PATH},g" \
	 -e "/-D.*LOCALEDIR=/s,[(]datadir[)]/,&../,g" \
	 ${WRKSRC}/src/Makefile
	${REINPLACE_CMD} -e "s,[(]datadir[)]/gnome/,(datadir)/,g" \
	 ${WRKSRC}/help/C/Makefile
	${REINPLACE_CMD} \
	 -e "/^datadir/s,${PREFIX}/share/gnome,${PREFIX}/share,g" \
	 ${WRKSRC}/po/Makefile

.include <bsd.port.post.mk>
