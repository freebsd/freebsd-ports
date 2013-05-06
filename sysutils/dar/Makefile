# Created by: Edson Brandi <ebrandi@fugspbr.org>
# $FreeBSD$

PORTNAME=	dar
PORTVERSION=	2.3.11
CATEGORIES=	sysutils archivers
MASTER_SITES=	SF

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	A full featured command-line backup tool, aimed for disks

USE_AUTOTOOLS=	libtool

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-build-html --datadir=${DATADIR} --disable-upx

CPPFLAGS+=	-DHAVE_DECL_GETOPT=0

MAN1=		dar.1 dar_cp.1 dar_manager.1 dar_slave.1 dar_xform.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=--with-libintl-prefix=${PREFIX}
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} *.html *.dtd *.txt *.jpg [CR]* ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/samples
	cd ${WRKSRC}/doc/samples && ${INSTALL_DATA} [JR]* [a-z]* ${DOCSDIR}/samples
	@${MKDIR} ${DOCSDIR}/mini-howto
	cd ${WRKSRC}/doc/mini-howto && ${INSTALL_DATA} *.html README ${DOCSDIR}/mini-howto
.endif

.include <bsd.port.mk>
