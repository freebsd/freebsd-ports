# $FreeBSD$

PORTNAME=	duff
PORTVERSION=	0.5.2
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Duplicate file finder

LICENSE=	ZLIB
LICENSE_GROUPS=	FSF OSI
LICENSE_NAME=	ZLIB license
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	auto-accept

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		duff.1

PORTDOCS=	README.SHA

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
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
