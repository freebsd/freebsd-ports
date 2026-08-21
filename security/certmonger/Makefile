PORTNAME=	certmonger
DISTVERSION=	0.79.20
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	https://pagure.io/certmonger/archive/${DISTVERSION}/

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Daemon to enrol with a CA and renew SSL certificates
WWW=		https://pagure.io/certmonger

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl		\
		libdbus-1.so:devel/dbus		\
		libidn2.so:dns/libidn2		\
		libjansson.so:devel/jansson	\
		libnspr4.so:devel/nspr		\
		libnss3.so:security/nss		\
		libpopt.so:devel/popt		\
		libuuid.so:misc/libuuid

USES=		autoreconf gettext gnome gssapi:mit iconv ldap pkgconfig \
		samba:lib ssl
USE_GNOME=	libxml2
USE_RC_SUBR=	${PORTNAME}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	${ICONV_CONFIGURE_ARG}
CFLAGS+=	-L${PREFIX}/lib -lintl

# There appears to be some hardcoded gettext dependencies
#OPTIONS_DEFINE=	NLS

post-patch:
		${REINPLACE_CMD} -e 's|"/etc/ipa|"${PREFIX}/etc/ipa|g' \
			${WRKSRC}/src/dogtag-ipa.c \
			${WRKSRC}/src/dogtag.c \
			${WRKSRC}/src/ipa.c

post-install:
		${MV}	${STAGEDIR}${ETCDIR}/${PORTNAME}.conf \
			${STAGEDIR}${ETCDIR}/${PORTNAME}.conf.sample
		${RMDIR} ${STAGEDIR}/var/lib/${PORTNAME}/cas
		${RMDIR} ${STAGEDIR}/var/lib/${PORTNAME}/requests

.include <bsd.port.mk>
