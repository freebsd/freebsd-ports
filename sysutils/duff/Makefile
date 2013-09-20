# $FreeBSD$

PORTNAME=	duff
PORTVERSION=	0.5.2
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Duplicate file finder

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/COPYING

USE_BZIP2=	yes
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		duff.1

PORTDOCS=	README.SHA

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB=	NLS="@comment "
.endif

post-patch:
.if !${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} '/^install-data-am:/s/install-dist_docDATA//' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
