# Created by: Jui-Nan Lin <jnlin@csie.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	trafficserver
PORTVERSION=	3.2.5
CATEGORIES=	www
MASTER_SITES=	APACHE/${PORTNAME}

MAINTAINER=	jnlin@csie.nctu.edu.tw
COMMENT=	Fast, scalable and extensible HTTP proxy server

LICENSE=	APACHE20

LIB_DEPENDS=	libexecinfo.so:${PORTSDIR}/devel/libexecinfo \
		libexpat.so:${PORTSDIR}/textproc/expat2 \
		libpcre.so:${PORTSDIR}/devel/pcre

USE_AUTOTOOLS=	autoconf automake libtool
USE_BZIP2=	yes
USES=		pkgconfig tcl
USE_OPENSSL=	yes
USE_SQLITE=	yes
USE_RC_SUBR=	${PORTNAME}
USE_LDCONFIG=	yes
USE_GCC=	any
ONLY_FOR_ARCHS=	i386 amd64

LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-expat=${LOCALBASE} \
		--with-pcre=${LOCALBASE} \
		--with-openssl=${OPENSSLBASE}

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,|| mv,|| cp -p,' ${WRKSRC}/proxy/config/Makefile.am

pre-configure:
	@${FIND} ${WRKSRC}/example ${WRKSRC}/plugins/conf_remap \
	    -name Makefile.am | ${XARGS} ${REINPLACE_CMD} \
		-e 's,CFLAGS+=,AM_CFLAGS=,' \
		-e 's,CXXFLAGS+=,AM_CXXFLAGS=,'
	@cd ${WRKSRC} && ${AUTORECONF} -i

post-configure:
	@${FIND} ${WRKSRC} -name 'Makefile' | ${XARGS} ${REINPLACE_CMD} \
	    -e 's,LIBTOOL_LINK_FLAGS = -R -R,LIBTOOL_LINK_FLAGS = -R,' \
	    -e 's,LDFLAGS = -rdynamic  *-R -R,LDFLAGS = -rdynamic -R,'

.include <bsd.port.post.mk>
