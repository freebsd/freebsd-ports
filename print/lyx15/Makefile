# New ports collection makefile for:	lyx
# Date created:		Sa  12 Okt 1996 19:20:51 MET DST
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	lyx
PORTVERSION=	1.2.1
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
RUN_DEPENDS=	gm4:${PORTSDIR}/devel/m4 \
		latex:${PORTSDIR}/print/teTeX

USE_XPM=	yes
USE_REINPLACE=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
USE_AUTOMAKE_VER=	15
AUTOMAKE=	${WRKSRC}/autogen.sh
AUTOCONF=	${TRUE}
CONFIGURE_ARGS=	--with-extra-lib="${LOCALBASE}/lib" \
		--with-extra-inc="${LOCALBASE}/include"
MAN1=		lyx.1 reLyX.1

.if defined(WITH_ASPELL)
LIB_DEPENDS+=	aspell.15:${PORTSDIR}/textproc/aspell
CONFIGURE_ARGS+=	--with-pspell \
			--with-pspell-lib="${LOCALBASE}/lib" \
			--with-pspell-include="${LOCALBASE}/include"
.endif

.if defined(WITH_ISPELL)
RUN_DEPENDS+=	ispell:${PORTSDIR}/textproc/ispell
.endif

pre-everything::
.if !defined(WITH_ASPELL)
	@${ECHO_MSG}
	@${ECHO_MSG} "If you want to compile with Aspell/Pspell support,"
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make WITH_ASPELL=yes\""
	@${ECHO_MSG}
.endif

.if !defined(WITH_ISPELL)
	@${ECHO_MSG}
	@${ECHO_MSG} "If you want to compile with Ispell support,"
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make WITH_ISPELL=yes\""
	@${ECHO_MSG}
.endif

post-extract:
	@${CP} -f ${FILESDIR}/xforms.m4 ${WRKSRC}/config

post-patch:
	@${FIND} ${WRKSRC} -name "configure.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|AC_CHECK_LIB(c,|AC_CHECK_FUNC(|g ; \
		 s|^INSTALL_SCRIPT=|#INSTALL_SCRIPT=|g'

.include <bsd.port.mk>
