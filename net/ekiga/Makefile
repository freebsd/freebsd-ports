# Ports collection Makefile for:	gnomemeeting
# Date created:				24/07/2001
# Whom:					roger@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gnomemeeting
PORTVERSION=	1.2.1
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:R}

MAINTAINER=	netchild@FreeBSD.org
COMMENT=	GNOME H323 Video Conferencing program, similar to NetMeeting

LIB_DEPENDS=	h323_r:${PORTSDIR}/net/openh323 \
		howl:${PORTSDIR}/net/howl

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	libgnomeui libbonobo gnomeprefix gnomehack evolutiondataserver \
		intlhack
USE_OPENLDAP=	yes
GCONF_SCHEMAS=	gnomemeeting.schemas
USE_SDL=	yes
USE_BISON=	yes
# Clear configure target so we stop getting binaries prefixed with i386-portbld-freebsd46
CONFIGURE_TARGET=
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV=	OSTYPE=${OPSYS} \
		CXXFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${PREFIX}/lib -L${LOCALBASE}/lib ${PTHREAD_LIBS}" \
		SDL_CONFIG=${LOCALBASE}/bin/sdl11-config \
		CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		PTLIBDIR=${PREFIX}

CONFIGURE_ARGS=	--with-pwlib-dir=${LOCALBASE} \
		--with-openh323-dir=${LOCALBASE} \
 		--with-ldap-dir=${LOCALBASE}

MAN1=	gnomemeeting.1

post-patch:
	${REINPLACE_CMD} -e 's:-lh323_FreeBSD_x86_r_s:-lh323_r:g; \
		s:-lpt_FreeBSD_x86_r_s:-lpt_r:g; \
		s:-lh323_FreeBSD_x86_r:-lh323_r:g; \
		s:-lpt_FreeBSD_x86_r:-lpt_r:g; \
		s: -DSTATIC_LIBS_USED::g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
