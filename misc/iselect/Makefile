# Created by: Ralf S. Engelschall <rse@engelschall.com>
# $FreeBSD$

PORTNAME=	iselect
PORTVERSION=	1.4.0
CATEGORIES=	misc
MASTER_SITES=	OSSP
MASTER_SITE_SUBDIR=	tool/iselect

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interactive Selection Tool

OPTIONS_DEFINE=	SLANG EXAMPLES
SLANG_DESC=	Link with slang

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/iselect man/man1/iselect.1.gz
PORTEXAMPLES=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSLANG}
LIB_DEPENDS+=	libslang.so:${PORTSDIR}/devel/libslang2
CONFIGURE_ARGS+=	--with-incdir=${LOCALBASE}/include \
			--with-libdir=${LOCALBASE}/lib
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS=|#CFLAGS=|g' ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/iselect ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/iselect.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/example && ${FIND} . | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
