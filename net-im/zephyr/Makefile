# Created by: Ben Kaduk <kaduk@mit.edu>
# $FreeBSD$

PORTNAME=	zephyr
DISTVERSION=	3.0.1
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	http://zephyr.1ts.org/export/2642/distribution/

MAINTAINER=	kaduk-fbsd@mit.edu
COMMENT=	Enterprise-scale distributed messaging system

LICENSE=	MIT

GNU_CONFIGURE=	yes
USES=		iconv libtool readline
USE_RC_SUBR=	zhm
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include

OPTIONS_DEFINE=		HEIMDAL
HEIMDAL_DESC=		Link against libss.so from security/heimdal

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MHEIMDAL}
BROKEN=		bad depobj
LIB_DEPENDS+=	libss.so.1:${PORTSDIR}/security/heimdal
.if defined(HEIMDAL_HOME)
KRB5_DIR?=	${HEIMDAL_HOME}
.else
KRB5_DIR?=	${LOCALBASE}
.endif
.else
LIB_DEPENDS+=	libss.so.2:${PORTSDIR}/devel/e2fsprogs-libss
KRB5_DIR?=	${DESTDIR}/usr
.endif

# it is an upstream bug that --with-krb5 needs a path
CONFIGURE_ARGS=	--with-krb5="${KRB5_DIR}"

# try to fix parallel (-jX) builds: add missing inter-source dependencies
post-patch:
	@${REINPLACE_CMD} -e \
		'/^eval\.o/,$$s,port\.h,& string_stack.h new_string.h, ; \
		s,_aux\.h,.h,' ${WRKSRC}/zwgc/Makefile.in

.include <bsd.port.mk>
