# New ports collection makefile for:	duff
# Date created:				2009-06-10
# Whom:					Jason E. Hale <bsdkaffee@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	duff
PORTVERSION=	0.5.2
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	bsdkaffee@gmail.com
COMMENT=	Duplicate file finder

LICENSE=	ZLIB
LICENSE_GROUPS=	FSF OSI COPYFREE
LICENSE_NAME=	ZLIB license
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	${_LICENSE_PERMS_DEFAULT}

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		duff.1

OPTIONS=	NLS "Native Language Support" on

PORTDOCS=	README.SHA

.include <bsd.port.options.mk>

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB=	NLS="@comment "
.endif

post-patch:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} '/^install-data-am:/s/install-dist_docDATA//' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
