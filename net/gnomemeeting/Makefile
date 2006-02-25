# Ports collection Makefile for:	gnomemeeting
# Date created:				24/07/2001
# Whom:					roger@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gnomemeeting
PORTVERSION=	0.98.5
PORTREVISION=	7
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.98

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	GNOME H323 Video Conferencing program, similar to NetMeeting

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/net/openh323-112:build

# note, we do not want to clean openh323, otherwise it has to build
# it all over again which can take several hours.
NOCLEANDEPENDS=	yes

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	libgnomeui libbonobo gnomeprefix gnomehack
USE_REINPLACE=	yes
USE_OPENLDAP=	yes
USE_BISON=	yes
# Clear configure target so we stop getting binaries prefixed with i386-portbld-freebsd46
CONFIGURE_TARGET=
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV=	OSTYPE=${OPSYS} \
		LIBS="-L${PREFIX}/lib -L${LOCALBASE}/lib ${PTHREAD_LIBS}" \
		PTLIBDIR=${PWLIBDIR} \
		OPENH323DIR=${OPENH323DIR} \
		SDL_CONFIG=${LOCALBASE}/bin/sdl11-config \
		CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}"

CONFIGURE_ARGS=	--with-ptlib-includes=${PWLIBDIR}/include/ptlib \
		--with-ptlib-libs=${PWLIBDIR}/lib \
		--with-openh323-includes=${OPENH323DIR}/include \
		--with-openh323-libs=${OPENH323DIR}/lib \
 		--with-ldap-includes=${LOCALBASE}/include \
 		--with-openldap-libs=${LOCALBASE}/lib

GCONF_SCHEMAS=	gnomemeeting.schemas
MAN1=		gnomemeeting.1

.include <bsd.port.pre.mk>

PWLIBDIR!=	cd ${PORTSDIR}/devel/pwlib152 && make -V WRKSRC
OPENH323DIR!=	cd ${PORTSDIR}/net/openh323-112 && make -V WRKSRC

.if ${ARCH} != "i386"
BROKEN=		"Configure fails on !i386"
.endif

post-patch:
	${REINPLACE_CMD} -E -e 's=-D[[:punct:][:alnum:]]+_DISABLE_DEPRECATED==g' \
		${WRKSRC}/src/Makefile.am \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.post.mk>
