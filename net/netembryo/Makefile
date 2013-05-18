# Created by: Emmanuel Richiardone (err@tollari.org)
# $FreeBSD$

PORTNAME=	netembryo
PORTVERSION=	0.1.1
CATEGORIES=	net
MASTER_SITES=		${MASTER_SITE_LOCAL} \
			http://pkgs.fedoraproject.org/repo/pkgs/netembryo/netembryo-0.1.1.tar.bz2/d5a3c96b37fe3e4fb1c49df1f7a4a16f/ \
			http://lscube.org/files/downloads/netembryo/
MASTER_SITE_SUBDIR=	rakuco

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Network abstraction library used by for feng, libnemesi, felix

LICENSE=	LGPL21

OPTIONS_DEFINE=	OPENSSL
OPTIONS_DEFAULT=OPENSSL

USE_BZIP2=	yes
USES=		pathfix pkgconfig
USE_GNOME=	glib20
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--disable-silent-rules
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENSSL}
USE_OPENSSL=	yes
CONFIGURE_ENV+=	OPENSSL_CFLAGS="-I${OPENSSLINC}" \
		OPENSSL_LIBS="-L${OPENSSLLIB}"
.else
CONFIGURE_ARGS+=--without-openssl
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|^CPPFLAGS=|#CPPFLAGS| ; \
		 s|freebsd[0-9]|freebsd|' ${WRKSRC}/configure

.include <bsd.port.mk>
