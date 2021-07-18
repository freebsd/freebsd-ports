# Created by: Andris Raugulis <moo@arthepsy.eu>

PORTNAME=	s6-rc
PORTVERSION=	0.5.2.2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.skarnet.org/software/${PORTNAME}/

MAINTAINER=	crest@rlwinm.de
COMMENT=	Skarnet.org service manager

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	execline>=2.7.0.0:lang/execline \
		skalibs>=2.10.0.0:devel/skalibs \
		s6>=2.10.0.0:sysutils/s6
RUN_DEPENDS=	execline>=2.7.0.0:lang/execline \
		skalibs>=2.10.0.0:devel/skalibs \
		s6>=2.10.0.0:sysutils/s6
LIB_DEPENDS=	libs6.so:sysutils/s6 \
		libskarnet.so:devel/skalibs

USES=		gmake

USE_LDCONFIG=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=--prefix=${PREFIX} \
	--with-include=${LOCALBASE}/include \
	--with-lib=${LOCALBASE}/lib/skalibs \
	--with-lib=${LOCALBASE}/lib/execline \
	--with-lib=${LOCALBASE}/lib/s6 \
	--with-dynlib=${LOCALBASE}/lib \
	--livedir=${LIVEDIR} \
	--enable-shared

LIVEDIR?=	/var/run/${PORTNAME}

DOCS=		AUTHORS COPYING INSTALL README doc/*.html
OPTIONS_DEFINE=	DOCS

post-install:
.for d in bin libexec
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${d}/*
.endfor
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libs6rc.so.${PORTVERSION}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
