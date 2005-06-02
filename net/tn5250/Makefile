# New ports collection makefile for:	tn5250
# Date created:			20 January 2000
# Whom:				Elias Mandouvalos <ocean@compulink.gr>
#
# $FreeBSD$
#

PORTNAME=	tn5250
PORTVERSION=	0.16.5
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	5250 Telnet protocol and Terminal

USE_REINPLACE=	yes
USE_LIBTOOL_VER=15
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--enable-os-dir=no
INSTALLS_SHLIB=	yes

MAN1=		lp5250d.1 scs2ascii.1 scs2pdf.1 scs2ps.1 tn5250.1
MAN5=		tn5250rc.5

.if defined(WITH_SLANG)
LIB_DEPENDS=	slang.1:${PORTSDIR}/devel/libslang
PKGNAMESUFFIX=	-slang
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -DUSE_CURSES" \
		LDFLAGS="-L${LOCALBASE}/lib -lcurses"
CONFIGURE_ARGS+=	--with-slang=yes
.else
CONFIGURE_ARGS+=	--with-slang=no
.endif

pre-everything::
.if !defined(WITH_SLANG)
	@${ECHO_MSG}
	@${ECHO_MSG} "If you want to compile with S/Lang support,"
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make WITH_SLANG=yes\""
	@${ECHO_MSG}
.endif

post-patch:
	@${FIND} ${WRKSRC}/src -name '*.[ch]' | ${XARGS} ${REINPLACE_CMD} -e \
		's|<malloc.h>|<stdlib.h>|g'

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/freebsd/5250keys ${PREFIX}/bin
.for file in README sample.termcap us.5250.kbd
	${INSTALL_DATA} ${WRKSRC}/freebsd/${file} ${DATADIR}
.endfor

.include <bsd.port.mk>
