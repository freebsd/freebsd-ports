PORTNAME=	atompaw
DISTVERSION=	4.2.0.5
CATEGORIES=	science
MASTER_SITES=	http://users.wfu.edu/natalie/papers/pwpaw/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tool for projector augmented wave functions for molecular simulations
WWW=		https://users.wfu.edu/natalie/papers/pwpaw/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		blaslapack:openblas fortran gmake libtool
MAKE_JOBS_UNSAFE=yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-linalg-prefix=${LOCALBASE}	\
		--with-linalg-libs=${BLASLIB}

OPTIONS_DEFINE=		DOCS LIBXC
OPTIONS_DEFAULT=	LIBXC

LIBXC_DESC=		Build with libxc
LIBXC_CONFIGURE_ENABLE=	libxc
LIBXC_LIB_DEPENDS=	libxc.so:science/libxc

PORTDOCS=	*

PLIST_FILES=	bin/atompaw \
		bin/atompaw_aeonly

.include <bsd.port.mk>
