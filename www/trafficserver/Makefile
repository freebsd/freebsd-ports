# New ports collection makefile for:	trafficserver
# Date created:		2010-08-15
# Whom:			Jui-Nan Lin <jnlin@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	trafficserver
PORTVERSION=	3.0.2
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	APACHE/${PORTNAME}

MAINTAINER=	jnlin@csie.nctu.edu.tw
COMMENT=	A fast, scalable and extensible HTTP proxy server

LICENSE=	AL2

LIB_DEPENDS=	execinfo.1:${PORTSDIR}/devel/libexecinfo \
		expat.6:${PORTSDIR}/textproc/expat2 \
		pcre.1:${PORTSDIR}/devel/pcre

USE_AUTOTOOLS=	autoconf automake libtool
USE_BZIP2=	yes
USE_ICONV=	yes
USE_OPENSSL=	yes
USE_SQLITE=	yes
USE_TCL=	yes
USE_RC_SUBR=	${PORTNAME}
USE_LDCONFIG=	yes

LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-expat=${LOCALBASE} \
		--with-pcre=${LOCALBASE}

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

post-configure:
	@${FIND} ${WRKSRC} -name 'Makefile' | ${XARGS} ${REINPLACE_CMD} \
	    -e 's,LIBTOOL_LINK_FLAGS = -R -R,LIBTOOL_LINK_FLAGS = -R,' \
	    -e 's,LDFLAGS = -rdynamic  *-R -R,LDFLAGS = -rdynamic -R,'

.include <bsd.port.post.mk>
