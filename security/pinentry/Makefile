# New ports collection makefile for:	pinentry
# Date created:		29 Jan 2003
# Whom:			michaelnottebrock@gmx.net
#
# $FreeBSD$
#

PORTNAME=	pinentry
PORTVERSION=	0.6.7
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/pinentry/ \
		http://tigress.com/lofi/
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.gz \
		common.tar.gz \
		jnlib.tar.gz

MAINTAINER=	michaelnottebrock@gmx.net

BUILD_DEPENDS=	autoconf:${PORTSDIR}/devel/autoconf \
		automake:${PORTSDIR}/devel/automake
LIB_DEPENDS=	gcrypt.6:${PORTSDIR}/security/libgcrypt \
		gnugetopt.1:${PORTSDIR}/devel/libgnugetopt \
		ksba.7:${PORTSDIR}/security/libksba

WANT_GTK=	yes
USE_LIBTOOL=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes
CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}" CPPFLAGS="${CPPFLAGS}"
CONFIGURE_ARGS+=--with-included-gettext=no

.include <bsd.port.pre.mk>

.if defined(WITH_QT)
#USE_QT_VER=	3
BROKEN=	The QT pinentry-helper is currently non-functional
.endif

.if defined(HAVE_GTK)
USE_GTK=	yes
.endif

post-extract:
	${MV} ${WRKDIR}/common ${WRKSRC}
	${MV} ${WRKDIR}/jnlib ${WRKSRC}

pre-configure:
	${REINPLACE_CMD} -e "s@-lpthread@${PTHREAD_LIBS}@g" \
		${WRKSRC}/acinclude.m4 ${WRKSRC}/aclocal.m4 ${WRKSRC}/configure
	cd ${WRKSRC}; ./autogen.sh

.include <bsd.port.post.mk>
