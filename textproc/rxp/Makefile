PORTNAME=	rxp
DISTVERSION=	1.5.2
CATEGORIES=	textproc
MASTER_SITES=	https://www.inf.ed.ac.uk/research/isddarch/admin/

MAINTAINER=	ports@virtual-estates.net
COMMENT=	Validating XML parser written in C
WWW=		https://www.cogsci.ed.ac.uk/~richard/rxp.html

LICENSE=	GPLv2

USES=		libtool
USE_LDCONFIG=	yes

OPTIONS_SINGLE=	CHAR_SIZE
OPTIONS_SINGLE_CHAR_SIZE=8 16
OPTIONS_DEFAULT=8
8_DESC=		8-bit characters (required by speech_tools, festival)
16_DESC=	16-bit characters (upstream's default)

CFLAGS+=	-Wno-empty-body
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
EXTRACT_AFTER_ARGS=	--exclude win32.h
MAKE_ENV+=	AM_LDFLAGS="-version-info 2:0:0"

post-patch:
	@${REINPLACE_CMD} -E -e 's|include/win32.h *||' \
	    -e 's,CHAR_SIZE=[0-9]+,CHAR_SIZE=${PORT_OPTIONS:C/[^0-9]//g},g' \
		${WRKSRC}/Makefile*

.include <bsd.port.mk>
