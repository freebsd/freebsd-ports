PORTNAME=	xapian-omega
PORTVERSION=	1.4.30
CATEGORIES=	www
MASTER_SITES=	https://oligarchy.co.uk/xapian/${PORTVERSION}/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	CGI search application built on Xapian
WWW=		https://xapian.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	xapian-core>=${PORTVERSION}:databases/xapian-core
LIB_DEPENDS=	libpcre2-8.so:devel/pcre2 \
		libxapian.so:databases/xapian-core

USES=		compiler:c++11-lang libtool localbase perl5 shebangfix tar:xz

CONFIGURE_ARGS=	--datarootdir=${DATADIR} --docdir=${DOCSDIR} \
		ac_cv_func_snprintf=snprintf
CONFIGURE_ENV=	XAPIAN_CONFIG=${LOCALBASE}/bin/xapian-config
GNU_CONFIGURE=	yes
USE_CXXSTD=	c++11

CONFLICTS_INSTALL=	xapian-omega12

PORTSCOUT=	limitw:1,even

SHEBANG_FILES=	dbi2omega htdig2omega mbox2omega

OPTIONS_DEFINE=	DOCS EXAMPLES ICONV
OPTIONS_DEFAULT=ICONV
ICONV_DESC=	Enable iconv character set conversion support

ICONV_CONFIGURE_ON=	ac_cv_search_iconv=${ICONV_LIB}
ICONV_CONFIGURE_WITH=	iconv
ICONV_USES=		iconv

post-install-DOCS-on:
	cd ${WRKSRC}/ && ${INSTALL_DATA} AUTHORS ChangeLog NEWS README TODO ${STAGEDIR}${DOCSDIR}/

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/omega.conf ${STAGEDIR}${EXAMPLESDIR}/
	cd ${WRKSRC}/ && ${COPYTREE_SHARE} templates ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
