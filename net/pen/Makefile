PORTNAME=	pen
PORTVERSION=	0.34.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://siag.nu/pub/pen/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Load balancer for UDP and TCP based protocols
WWW=		https://siag.nu/pen/

LICENSE=	GPLv2

USES=		cpe ssl
CPE_VENDOR=	${PORTNAME}_project
USE_RC_SUBR=	pen

GNU_CONFIGURE=			yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=			--with-daemon \
				--with-docdir=${DOCSDIR} \
				--with-ssl=${OPENSSLBASE} \
				--without-geoip
CPPFLAGS+=			-I${LOCALBASE}/include
LIBS+=				-L${LOCALBASE}/lib

FETCH_ARGS+=	--user-agent=curl/7.68.0

PLIST_FILES=	bin/mergelogs \
		bin/pen \
		bin/penctl \
		bin/penlog \
		bin/penlogd \
		share/man/man1/mergelogs.1.gz \
		share/man/man1/pen.1.gz \
		share/man/man1/penctl.1.gz \
		share/man/man1/penlog.1.gz \
		share/man/man1/penlogd.1.gz
PORTDOCS=	AUTHORS COPYING ChangeLog HOWTO README penstats

OPTIONS_DEFINE=		DEBUG DOCS KQUEUE
OPTIONS_DEFAULT=	KQUEUE
KQUEUE_DESC=		Use kqueue backend

.if defined(WITH_FDSETSIZE)
CONFIGURE_ARGS+=	--with-fd_setsize=${WITH_FDSETSIZE}
.endif

DEBUG_CONFIGURE_ENABLE=	debugging
KQUEUE_CONFIGURE_ON=	--with-kqueue
KQUEUE_CONFIGURE_OFF=	--with-poll

post-patch:
	@${REINPLACE_CMD} 's/-pg//' ${WRKSRC}/configure

.include <bsd.port.mk>
