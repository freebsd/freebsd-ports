# New ports collection makefile for:	lyx
# Date created:		Sa  12 Okt 1996 19:20:51 MET DST
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	lyx
PORTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.lyx.org/pub/lyx/stable/ \
		ftp://ftp.sdsc.edu/pub/other/lyx/stable/ \
		ftp://gd.tuwien.ac.at/publishing/tex/lyx/stable/

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4 \
		latex:${PORTSDIR}/print/teTeX
LIB_DEPENDS=	intl.4:${PORTSDIR}/devel/gettext \
		forms.1:${PORTSDIR}/x11-toolkits/xforms
RUN_DEPENDS=	${BUILD_DEPENDS}

.if defined(WITH_ASPELL)
LIB_DEPENDS+= aspell.15:${PORTSDIR}/textproc/aspell
CONFIGURE_ARGS+=--with-pspell
.endif

.if defined(WITH_ISPELL)
RUN_DEPENDS+=	ispell:${PORTSDIR}/textproc/ispell
.endif

pre-everything::
.if !defined(WITH_ASPELL) && !defined(WITH_ISPELL)
	#
	# If you want to compile with Aspell/Pspell or Ispell support,
	# hit Ctrl-C right now and use
	#	"make WITH_ASPELL=yes"
	# or
	#	"make WITH_ISPELL=yes"
	#
.endif

USE_GMAKE=	yes
USE_XPM=	yes
USE_REINPLACE=	yes
REINPLACE_ARGS=	-i ""
USE_PERL5=	yes
USE_AUTOMAKE_VER=15
AUTOMAKE=	${WRKSRC}/autogen.sh
AUTOCONF=	${TRUE}
CONFIGURE_ARGS=	--with-extra-lib="${X11BASE}/lib ${LOCALBASE}/lib" \
		--with-extra-inc="${X11BASE}/include/X11 ${X11BASE}/include \
		${LOCALBASE}/include"
CONFIGURE_ENV+=	LDFLAGS="-L${X11BASE}/lib -lXpm -lX11"
MAN1=		lyx.1 reLyX.1

post-patch:
	@${FIND} ${WRKSRC} -name "configure.in" | ${XARGS} ${REINPLACE_CMD} \
		-e 's|-lxforms|-lforms|g' \
		-e 's|AC_CHECK_LIB(c,|AC_CHECK_FUNC(|g' \
		-e 's|^INSTALL_SCRIPT=|#INSTALL_SCRIPT=|g'

.include <bsd.port.mk>
