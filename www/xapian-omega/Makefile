# Created by: Henrik Brix Andersen <brix@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xapian-omega
PORTVERSION=	1.4.9
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	https://oligarchy.co.uk/xapian/${PORTVERSION}/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	CGI search application built on Xapian

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	xapian-core>=${PORTVERSION}:databases/xapian-core
LIB_DEPENDS=	libpcre.so:devel/pcre \
		libxapian.so:databases/xapian-core

CONFLICTS_INSTALL=	xapian-omega12

OPTIONS_DEFINE=	DOCS EXAMPLES ICONV
OPTIONS_DEFAULT=ICONV
ICONV_DESC=	Enable iconv character set conversion support

PORTSCOUT=	limitw:1,even

USES=		compiler:c++11-lang libtool localbase perl5 shebangfix tar:xz

CONFIGURE_ARGS=	--datarootdir=${DATADIR} --docdir=${DOCSDIR}
CONFIGURE_ENV=	PCRE_CONFIG=${LOCALBASE}/bin/pcre-config \
		XAPIAN_CONFIG=${LOCALBASE}/bin/xapian-config
GNU_CONFIGURE=	yes
USE_CXXSTD=	c++11
USE_LDCONFIG=	yes

SHEBANG_FILES=	dbi2omega htdig2omega mbox2omega

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
	cd ${WRKSRC}/ && ${COPYTREE_SHARE} templates ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
