# Created by: Stephen Kiernan <sk-ports@vegamuse.org>
# $FreeBSD$

PORTNAME=	mahogany
PORTVERSION=	0.67
PORTREVISION=	7
CATEGORIES=	mail
MASTER_SITES=	SF/${PORTNAME}/Mahogany/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11 mail and news client

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_WX=		2.6+
WX_CONF_ARGS=	absolute
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-dspam --with-python=none
ALL_TARGET=	all locales
INSTALL_TARGET=	install_bin install_locale

OPTIONS_DEFINE=	NLS

MAN1=		M.1 mahogany.1

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "sparc64"
BROKEN=		Does not compile with GCC 4.2
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|-DOPENSSL_NO_KRB5||; \
		 s|-O2|${CFLAGS}|; \
		 s|-Wno-pointer-sign||' \
		 ${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's|$$(DATADIR)/locale|$$(DESTDIR)/share/locale|' \
		${WRKSRC}/locale/Makefile

.include <bsd.port.mk>
