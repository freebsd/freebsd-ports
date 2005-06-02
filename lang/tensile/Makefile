# ex:ts=8
# Ports collection makefile for:	tensile
# Date created:			May 6, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	tensile
PORTVERSION=	0.9
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	lang
MASTER_SITES=	http://savannah.gnu.org/download/nsl/ \
		http://iling.nw.ru/~artem/downloads/ \
		http://unixpages.org/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Programming language designed for especially complex processing texts

LIB_DEPENDS=	utils.1:${PORTSDIR}/lang/libutils

USE_LIBLTDL=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=15
LIBTOOLFLAGS=	# none
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-module-postgres
MAKE_ARGS=	CFLAGS="${CFLAGS}"
INSTALLS_SHLIB=	yes

MAN1=		sl.1 sla.1
MAN7=		docstrip.7t sl_crypt.7t sl_files.7t sl_fpmath.7t sl_int64.7t \
		sl_ncurses.7t sl_postgres.7t sl_rand.7t sl_readline.7t

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 600000
BROKEN=		"Coredump during build on FreeBSD >= 6.x"
.endif

.if ${OSVERSION} < 400010
LIB_DEPENDS+=	ncurses.5:${PORTSDIR}/devel/ncurses
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|= -module$$|= -module -avoid-version|g'

.include <bsd.port.post.mk>
