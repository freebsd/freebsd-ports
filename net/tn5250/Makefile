# New ports collection makefile for:	tn5250
# Date created:			20 January 2000
# Whom:				Elias Mandouvalos <ocean@compulink.gr>
#
# $FreeBSD$
#

PORTNAME=	tn5250
PORTVERSION=	0.16.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

USE_AUTOMAKE=	yes
AUTOMAKE_ARGS=	--include-deps
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--enable-os-dir=no
INSTALLS_SHLIB=	yes

MAN1=		scs2ascii.1 scs2pdf.1 tn5250.1 lp5250d.1

.if defined(WITH_SLANG)
LIB_DEPENDS=	slang.1:${PORTSDIR}/devel/libslang
PKGNAMESUFFIX=	-slang
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS+=	--with-slang
.endif

.if !defined(WITH_SLANG)
pre-everything:
	@${ECHO_MSG}
	@${ECHO_MSG} "If you want to compile with S/Lang support,"
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make WITH_SLANG=yes\""
	@${ECHO_MSG}
.endif

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/freebsd/5250keys ${PREFIX}/bin
.for file in README sample.termcap us.5250.kbd
	${INSTALL_DATA} ${WRKSRC}/freebsd/${file} ${DATADIR}
.endfor

.include <bsd.port.mk>
