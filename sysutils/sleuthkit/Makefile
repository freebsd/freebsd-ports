# Created by: Pieter Danhieux <opr@bsdaemon.be>
# $FreeBSD$

PORTNAME=	sleuthkit
PORTVERSION=	4.5.0
CATEGORIES=	sysutils security
MASTER_SITES=	https://github.com/sleuthkit/sleuthkit/releases/download/sleuthkit-${PORTVERSION}/

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Tools and library for filesystem forensic analysis

LICENSE=	CPL IBM GPLv2
LICENSE_COMB=	multi
LICENSE_NAME_CPL=Common Public License
LICENSE_NAME_IBM=IBM Public License
LICENSE_FILE_CPL=${WRKSRC}/licenses/cpl1.0.txt
LICENSE_FILE_IBM=${WRKSRC}/licenses/IBM-LICENSE
LICENSE_PERMS_CPL=dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_IBM=dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	p5-DateTime-TimeZone>=0:devel/p5-DateTime-TimeZone \
		exif:graphics/exif

CONFLICTS=	ja-ls-[0-9]* icat-[0-9]*

CPPFLAGS+=	-D_WITH_GETLINE
GNU_CONFIGURE=	yes
USES=		libtool perl5 sqlite
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
DATADIR=	${PREFIX}/share/tsk

PORTDOCS=	NEWS.txt README.md

OPTIONS_DEFINE=	AFFLIB DOCS LIBEWF
AFFLIB_DESC=	Build with AFFLIB support
LIBEWF_DESC=	Build with EWF support
OPTIONS_DEFAULT=LIBEWF

AFFLIB_LIB_DEPENDS=	libafflib.so:sysutils/afflib
AFFLIB_CONFIGURE_WITH=	afflib=${LOCALBASE}

LIBEWF_LIB_DEPENDS=	libewf.so:devel/libewf
LIBEWF_CONFIGURE_WITH=	libewf=${LOCALBASE}

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
