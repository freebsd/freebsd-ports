# New ports collection makefile for:	xmule
# Date created:		Tue Mar 11 05:06:20 UTC 2003
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xmule
PORTVERSION=	1.6.0
CATEGORIES=	net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	xmule

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Port of eMule eDonkey P2P client using wxWindows class library

#FORBIDDEN=	Multiple vulnerabilities, see \
#	   	http://security.e-matters.de/advisories/022003.html

LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext \
		expat.4:${PORTSDIR}/textproc/expat2 \
		wx_gtk.2:${PORTSDIR}/x11-toolkits/wxgtk-devel
RUN_DEPENDS=	wget:${PORTSDIR}/ftp/wget

USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehier \
		gnomehack \
		gnomeprefix
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-included-gettext \
		--with-libintl-prefix=${LOCALBASE} \
		--with-wx-config=${WX_CONFIG}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib ${PTHREAD_LIBS}"

WX_CONFIG?=	${X11BASE}/bin/wx-config

post-patch:
# it works for FreeBSD as well
	@${REINPLACE_CMD} -E \
		-e 's|(Linux)|FreeBSD/\1|' \
		${WRKSRC}/src/*.cpp
# remove ^M
	@${REINPLACE_CMD} -E \
		-e 's|||' \
		${WRKSRC}/src/MD5Sum.cpp
# do not install a generic named ed2k binary 
	@${REINPLACE_CMD} -E \
		-e 's|^(bin_PROGRAMS.+)ed2k|\1|' \
		${WRKSRC}/src/Makefile.in
# update documentation regarding aforementioned change
	@${REINPLACE_CMD} -E \
		-e 's|/usr/local/bin/ed2k|${PREFIX}/bin/${PORTNAME}-ed2k-handler|' \
		${WRKSRC}/ED2K-Links.HOWTO

pre-configure:
	@${FIND} ${WRKSRC} -type f -name "Makefile.in" | \
		${XARGS} -x -n 10 \
		${REINPLACE_CMD} -E \
		-e 's!^(AUTOCONF|AUTOHEADER|AUTOMAKE|ACLOCAL).*$$!\1=${TRUE}!'

post-build:
# build the generic named ed2k binary
# it will installed in an adhoc fashion
	@cd ${BUILD_WRKSRC}/src; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ed2k

post-install:
# do not install a generic named ed2k binary
# install it under a more specific name
	@${INSTALL_PROGRAM} ${WRKSRC}/src/ed2k \
		${PREFIX}/bin/${PORTNAME}-ed2k-handler

.include <bsd.port.pre.mk>

.if exists(${WX_CONFIG})
# detect if wxgtk was linked against gtk1 or gtk2
DECISION_GTK_1_OR_2!=	${WX_CONFIG} --static --libs
.else
DECISION_GTK_1_OR_2=	""
.endif

.if ${DECISION_GTK_1_OR_2:M*glib-2.0} != ""
USE_GNOME+=	gtk20
.else
USE_GNOME+=	gtk12
.endif

.include <bsd.port.post.mk>
