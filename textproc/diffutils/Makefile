# Created by: Garrett Rooney <rooneg@electricjellyfish.net>
# $FreeBSD$

PORTNAME=	diffutils
PORTVERSION=	3.3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	diffutils

MAINTAINER=	johans@FreeBSD.org
COMMENT=	The GNU diff utilities

LIB_DEPENDS=	sigsegv:${PORTSDIR}/devel/libsigsegv

USES=		charsetfix
USE_XZ=		yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=g

INFO=		diffutils
MAN1=		gcmp.1 gdiff.1 gdiff3.1 gsdiff.1

post-patch:
	@${REINPLACE_CMD} -e '/^mkdir/s:@mkdir_p@:${MKDIR}:' \
		${WRKSRC}/po/Makefile.in.in

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
