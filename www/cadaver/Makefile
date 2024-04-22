PORTNAME=	cadaver
PORTVERSION=	0.24
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	https://notroj.github.io/cadaver/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Commandline client for DAV
WWW=		https://notroj.github.io/cadaver/

LIB_DEPENDS=	libneon.so:www/neon

USES=		ssl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-netrc --with-ssl
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

PLIST_FILES=	bin/cadaver \
		share/man/man1/cadaver.1.gz

# Neither expat nor libneon are needed at all, but the configure
# script breaks if it can not find the Makefile* in them. Exclude
# them to be sure, a stray .h is not included instead of what's
# found under PREFIX (installed by the neon port):
EXTRACT_AFTER_ARGS=	\
		--exclude '${PORTNAME}-${PORTVERSION}/lib/expat/*.[ch]' \
		--exclude '${PORTNAME}-${PORTVERSION}/lib/intl/*.[ch]' \
		--exclude '${PORTNAME}-${PORTVERSION}/lib/neon/*.[ch]' \
		--exclude 'glob.[ch]' --exclude 'mkstemp.[ch]'	\
		--exclude 'tempname.[ch]' --exclude 'basename.[ch]'

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

USES+=		cpe
CPE_VENDOR=	webdav

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext iconv
CONFIGURE_ARGS+=${ICONV_CONFIGURE_ARG} \
		--with-libintl-prefix=${LOCALBASE}
LANGS=en@quot es
.for lang in ${LANGS}
PLIST_FILES+=	share/locale/${lang}/LC_MESSAGES/cadaver.mo
.endfor
.else
CONFIGURE_ARGS+=--disable-nls \
		--without-libiconv-prefix \
		--without-libintl-prefix
.endif

NEON_VERSION=	31 32

post-patch:
	@${REINPLACE_CMD} 's,27 28 29,& ${NEON_VERSION},' ${WRKSRC}/configure

.include <bsd.port.mk>
