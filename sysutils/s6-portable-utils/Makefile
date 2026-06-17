PORTNAME=	s6-portable-utils
DISTVERSION=	2.3.1.2
CATEGORIES=	sysutils
MASTER_SITES=	https://www.skarnet.org/software/${PORTNAME}/

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Skarnet.org Unix utilities
WWW=		https://skarnet.org/software/s6-portable-utils/

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libskarnet.so:devel/skalibs

USES=		gmake
USE_LDCONFIG=	yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--with-default-path=${LOCALBASE}/bin:/usr/bin:/bin \
		--with-include=${LOCALBASE}/include \
		--with-dynlib=${LOCALBASE}/lib \
		--with-lib=${LOCALBASE}/lib \
		--enable-shared

OPTIONS_DEFINE=	DOCS

DOCS=		AUTHORS README doc/*.html

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
