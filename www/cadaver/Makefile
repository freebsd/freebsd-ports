PORTNAME=	cadaver
DISTVERSION=	0.26
CATEGORIES=	www
MASTER_SITES=	https://notroj.github.io/cadaver/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Commandline client for DAV
WWW=		https://notroj.github.io/cadaver/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libneon.so:www/neon

USES=		cpe localbase:ldflags pkgconfig ssl
CPE_VENDOR=	webdav
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-netrc \
		--with-ssl

# Neither expat nor libneon are needed at all, but the configure
# script breaks if it can not find the Makefile* in them. Exclude
# them to be sure, a stray .h is not included instead of what's
# found under PREFIX (installed by the neon port):
EXTRACT_AFTER_ARGS=	--exclude '${PORTNAME}-${DISTVERSION}/lib/expat/*.[ch]' \
			--exclude '${PORTNAME}-${DISTVERSION}/lib/intl/*.[ch]' \
			--exclude '${PORTNAME}-${DISTVERSION}/lib/neon/*.[ch]' \
			--exclude 'glob.[ch]' --exclude 'mkstemp.[ch]' \
			--exclude 'tempname.[ch]' --exclude 'basename.[ch]'

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext iconv
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
