# Created by: Jui-Nan Lin <jnlin@csie.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	trafficserver
PORTVERSION=	3.2.4
CATEGORIES=	www
MASTER_SITES=	APACHE/${PORTNAME}

MAINTAINER=	jnlin@csie.nctu.edu.tw
COMMENT=	A fast, scalable and extensible HTTP proxy server

LICENSE=	AL2

LIB_DEPENDS=	execinfo:${PORTSDIR}/devel/libexecinfo \
		expat:${PORTSDIR}/textproc/expat2 \
		pcre:${PORTSDIR}/devel/pcre

MAN1=		traffic_shell.1

USE_AUTOTOOLS=	autoconf automake libtool
USE_BZIP2=	yes
USES=		iconv
USE_OPENSSL=	yes
USE_SQLITE=	yes
USE_TCL=	yes
USE_RC_SUBR=	${PORTNAME}
USE_LDCONFIG=	yes

LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-expat=${LOCALBASE} \
		--with-pcre=${LOCALBASE}

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800505 || (${OSVERSION} >= 900000 && ${OSVERSION} < 900012)
BUILD_DEPENDS=	xz>0:${PORTSDIR}/archivers/xz
RUN_DEPENDS=	xz>0:${PORTSDIR}/archivers/xz
.endif

.if ${OSVERSION} < 800000 && ${ARCH} == "amd64"
BROKEN=		does not compile on 7.X/amd64
.endif

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64
.endif

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
