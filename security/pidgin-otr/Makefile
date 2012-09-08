# $FreeBSD$

PORTNAME=	otr
PORTVERSION=	4.0.0
# Please do not bump PORTREVISION for this port unless you have
# confirmed via testing that it is necessary
CATEGORIES=	security net-im net
MASTER_SITES=	http://www.cypherpunks.ca/otr/
PKGNAMEPREFIX=	pidgin-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.asc
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	dougb@FreeBSD.org
COMMENT=	Allows deniable private conversations using Pidgin

BUILD_DEPENDS=	${LOCALBASE}/bin/pidgin:${PORTSDIR}/net-im/pidgin \
		pkgconf>0:${PORTSDIR}/devel/pkgconf
LIB_DEPENDS=	otr.5:${PORTSDIR}/security/libotr \
		gcrypt:${PORTSDIR}/security/libgcrypt \
		purple:${PORTSDIR}/net-im/libpurple

MAKE_JOBS_SAFE=	yes

USE_GMAKE=	yes
USE_GNOME=	intltool
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes

CPPFLAGS+=	${PTHREAD_CFLAGS} -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CONFIGURE_ARGS=	--with-libotr-prefix=${LOCALBASE}/lib \
		--with-libotr-inc-prefix=${LOCALBASE}/include

verify: checksum
	gpg --verify ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}.asc

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/configure

.include <bsd.port.mk>
