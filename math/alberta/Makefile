PORTNAME=	alberta
DISTVERSION=	3.0.3
PORTREVISION=	1
CATEGORIES=	math
PKGNAMESUFFIX=	-fem

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Adaptive multi-level finite element toolbox
WWW=		https://www.alberta-fem.de/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gsed:textproc/gsed \
		opendx>0:graphics/opendx
LIB_DEPENDS=	libltdl.so:devel/libltdl
RUN_DEPENDS=	opendx>0:graphics/opendx # binaries aren't linked with it, not sure if it is really used

USES=		autoreconf fortran gl gmake libtool localbase:ldflags motif pkgconfig xorg
USE_GL=		gl
USE_XORG=	xt
USE_LDCONFIG=	yes

USE_GITLAB=	yes
GL_SITE=	https://gitlab.mathematik.uni-stuttgart.de/ians-nmh
GL_ACCOUNT=	alberta
GL_PROJECT=	alberta3
GL_TAGNAME=	920315ae1bbfd1b1fb6672d916619ac37a411e95

GNU_CONFIGURE=	yes

LDFLAGS+=	-lXm -lXt -pthread # link breaks without these

MAKE_JOBS_UNSAFE=	yes # otherwise it begins to rebuild something during stage and fails

INSTALL_TARGET=	install-strip

BINARY_ALIAS=	make=${GMAKE} sed=gsed

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

.include <bsd.port.mk>
