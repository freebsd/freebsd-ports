# New ports collection makefile for:	iiimf-gnome-im-switcher
# Date created:		10 Sep 2004
# Whom:			Kuang-che Wu <kcwu@csie.org>
#
# $FreeBSD$
#

PORTNAME=	gnome-im-switcher
PORTVERSION=	${IIIMF_VER:S/_/./g:C/-.*//}
CATEGORIES=	textproc
MASTER_SITES=	http://www.openi18n.org/download/im-sdk/src/
PKGNAMEPREFIX=	iiimf-
DISTNAME=	im-sdk-src-${IIIMF_VER}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kcwu@csie.org
COMMENT=	IIIMF gnome input method switcher

USE_X_PREFIX=	yes

IIIMF_VER=	r12_1-svn2002
USE_REINPLACE=  yes
USE_GMAKE=	yes
USE_GNOME=	intltool gconf2 libglade2 libgnomeui \
		gnomepanel gnomeprefix gnomehack
WANT_AUTOCONF_VER=253
WANT_AUTOHEADER_VER=253
WANT_AUTOMAKE_VER=15
WANT_LIBTOOL_VER=15

WRKSRC=         ${WRKDIR}/${DISTNAME:S/src-//}/gnome-im-switcher
PATCH_WRKSRC=   ${WRKDIR}/${DISTNAME:S/src-//}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 503000
IGNORE=         "It is supported on FreeBSD 5.3 and later"
.endif

.if ${ARCH} != "i386"
IGNORE=	"${ARCH} is not support."
.endif

GNU_CONFIGURE=	yes
MAKE_ARGS+=	LIBTOOL="${LIBTOOL} --tag=CXX"
UPDATE_ARGS+=	ACLOCAL=${ACLOCAL} AUTOMAKE=${AUTOMAKE} \
		AUTOHEADER=${AUTOHEADER} AUTOCONF=${AUTOCONF} \
		LIBTOOL=${LIBTOOL} LIBTOOLIZE=${LIBTOOLIZE}

post-patch:
	${REINPLACE_CMD} -e "s,/usr/lib/im,${PREFIX}/lib/im,g" \
		${WRKSRC}/../acfiles/im_common.m4
	${REINPLACE_CMD} -e "/GNOMECC_DATA_DIR/s,/share/,&gnome/,g" \
		${WRKSRC}/configure.in

pre-configure:
	(cd ${WRKSRC}/.. && ${GMAKE} ${UPDATE_ARGS} update-acfiles)
	(cd ${WRKSRC}/../acfiles/ && ${TOUCH} ltconfig)
	(cd ${WRKSRC} && ${TOUCH} ltconfig)
	(cd ${WRKSRC} && ${LOCALBASE}/bin/intltoolize --copy --force --automake)
	(cd ${WRKSRC} && ${LIBTOOLIZE} --force --copy)
	(cd ${WRKSRC} && ${ACLOCAL} -I ../acfiles -I /usr/local/share/aclocal)
	(cd ${WRKSRC} && ${AUTOHEADER})
	(cd ${WRKSRC} && ${AUTOMAKE} --add-missing --gnu)
	(cd ${WRKSRC} && ${AUTOCONF})

post-configure:
	${REINPLACE_CMD} -e "s,[(]libdir[)]/bonobo/server,{exec_prefix}/libdata/bonobo/server,g" \
		${WRKSRC}/src/Makefile
	${REINPLACE_CMD} -e "s,[(]datadir[)]/gnome/,(datadir)/,g" \
		${WRKSRC}/help/C/Makefile

.include <bsd.port.post.mk>
