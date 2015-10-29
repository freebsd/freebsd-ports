# Created by: Sergei Kolobov <sergei@kolobov.com>
# $FreeBSD$

PORTNAME=	libgpg-error
PORTVERSION=	1.20
PORTREVISION=	1
CATEGORIES=	security devel
MASTER_SITES=	GNUPG

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Common error values for all GnuPG components

OPTIONS_DEFINE=	DOCS NLS

USES=		gmake libtool tar:bzip2
USE_LDCONFIG=		yes
GNU_CONFIGURE=		yes
MAKE_JOBS_UNSAFE=	yes
CPP+=			-P
CONFIGURE_ARGS+=	--enable-static=yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext iconv
CONFIGURE_ARGS+=	${ICONV_CONFIGURE_ARG} \
		--with-libintl-prefix=${LOCALBASE}
PLIST_SUB=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB=	NLS="@comment "
.endif

DOCS=		AUTHORS ChangeLog NEWS README
INFO=		gpgrt

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
