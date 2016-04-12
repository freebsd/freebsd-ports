# Created by: Ralf S. Engelschall <rse@engelschall.com>
# $FreeBSD$

PORTNAME=	iselect
PORTVERSION=	1.4.0
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	OSSP/tool/iselect

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interactive Selection Tool

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		ncurses shebangfix
SHEBANG_FILES=	example/gotourl/gotourl \
		example/ilogin/ilogin \
		example/melm/melm \
		example/mtin/mtin \
		example/scvs/scvs
perl_OLD_CMD=	/sw/bin/perl
GNU_CONFIGURE=	yes
MAKE_ARGS=	LDFLAGS="${LDFLAGS}"

PLIST_FILES=	bin/iselect man/man1/iselect.1.gz
PORTEXAMPLES=	*

OPTIONS_DEFINE=	SLANG EXAMPLES
SLANG_DESC=	Link with slang
SLANG_LIB_DEPENDS=	libslang.so:devel/libslang2
SLANG_CONFIGURE_ON=	--with-incdir=${LOCALBASE}/include \
			--with-libdir=${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS=|#CFLAGS=|g' \
		-e 's|-lcurses|-lncurses|' ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/iselect ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/iselect.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/example && ${FIND} . | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
