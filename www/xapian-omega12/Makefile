# Created by: Henrik Brix Andersen <brix@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xapian-omega
PORTVERSION=	1.2.25
CATEGORIES=	www
MASTER_SITES=	https://oligarchy.co.uk/xapian/${PORTVERSION}/ \
		LOCAL/sunpoet
PKGNAMESUFFIX=	12

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	CGI search application built on Xapian

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpcre.so:devel/pcre \
		libxapian.so:databases/xapian-core12

USES=		libtool localbase perl5 shebangfix tar:xz

CONFIGURE_ARGS=	--datarootdir=${DATADIR} --docdir=${DOCSDIR}
CONFIGURE_ENV=	PCRE_CONFIG=${LOCALBASE}/bin/pcre-config \
		XAPIAN_CONFIG=${LOCALBASE}/bin/xapian-config
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CONFLICTS_INSTALL=	xapian-omega

PORTSCOUT=	limitw:1,even

SHEBANG_FILES=	dbi2omega htdig2omega mbox2omega

OPTIONS_DEFINE=	DOCS EXAMPLES ICONV
OPTIONS_DEFAULT=ICONV
ICONV_DESC=	Enable iconv character set conversion support

ICONV_CONFIGURE_ON=	ac_cv_search_iconv=${ICONV_LIB}
ICONV_CONFIGURE_WITH=	iconv
ICONV_USES=		iconv

post-patch:
	@${REINPLACE_CMD} \
		-e '/^dist_sysconf_DATA = /d' \
		-e '/^pkglibbindir = / s| = .*$$| = ${WWWDIR}/cgi-bin|' \
			${WRKSRC}/Makefile.in

post-install-DOCS-on:
	cd ${WRKSRC}/ && ${INSTALL_DATA} AUTHORS ChangeLog NEWS README TODO ${STAGEDIR}${DOCSDIR}/

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/omega.conf ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
