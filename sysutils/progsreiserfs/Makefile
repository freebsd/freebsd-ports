# Created by: Florent Thoumie <flz@xbsd.org>
# $FreeBSD$

PORTNAME=	progsreiserfs
DISTVERSION=	0.3.1-rc8
PORTREVISION=	7
CATEGORIES=	sysutils
MASTER_SITES=	http://www.cgsecurity.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utilities and library to manipulate ReiserFS partitions

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-debug --disable-Werror
CFLAGS+=	-Dgetopt_long_only=getopt_long

EXTRA_PATCHES=	${FILESDIR}/extrapatch-progsreiserfs_libmisc_Makefile.in

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=--disable-nls
.endif

post-patch:
	@${REINPLACE_CMD} '/_LDADD =/s/=/= $$(INTLLIBS)/' \
		${WRKSRC}/demos/Makefile.in
	@${REINPLACE_CMD} -e 's|sys/int_types.h|inttypes.h|' \
		${WRKSRC}/libreiserfs/tools.c ${WRKSRC}/include/reiserfs/*

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so

.include <bsd.port.mk>
