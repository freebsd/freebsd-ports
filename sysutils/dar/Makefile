# Created by: Edson Brandi <ebrandi@fugspbr.org>
# $FreeBSD$

PORTNAME=	dar
PORTVERSION=	2.4.12
PORTREVISION=	1
CATEGORIES=	sysutils archivers
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command-line backup tool, aimed for disks

LICENSE=	GPLv2 # (or later)

USES=		pathfix shebangfix libtool
SHEBANG_FILES=	doc/samples/dar_backup doc/samples/*.bash doc/samples/*.sh
USE_GCC=	any
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${DATADIR} --disable-build-html \
		--disable-upx --disable-libgcrypt-linking \
		--disable-ea-support --disable-nodump-flag \
		--disable-gnugetopt
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

OPTIONS_DEFINE=		DOCS LZO NLS
OPTIONS_SUB=		yes

LZO_DESC=		Support lzo compression via liblzo2
LZO_LIB_DEPENDS=	liblzo2.so:${PORTSDIR}/archivers/lzo2
LZO_CONFIGURE_ENABLE=	liblzo2-linking
NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.options.mk>

.if ${OSVERSION} < 1000052
LIB_DEPENDS+=	libexecinfo.so:${PORTSDIR}/devel/libexecinfo
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/LIBS/s|-lpthread|-pthread|' ${WRKSRC}/configure
	@${FIND} ${WRKSRC}/doc -name "Makefile.in" | ${XARGS} \
		${REINPLACE_CMD} -e \
		's|$$(pkgdatadir)|$$(docdir)|g'

.include <bsd.port.mk>
