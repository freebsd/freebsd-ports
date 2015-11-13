# Created by: Henrik Brix Andersen <brix@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xapian-omega
PORTVERSION=	1.2.21
CATEGORIES=	www
MASTER_SITES=	http://oligarchy.co.uk/xapian/${PORTVERSION}/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	CGI search application built on Xapian

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre \
		libxapian.so:${PORTSDIR}/databases/xapian-core

OPTIONS_DEFINE=	DOCS EXAMPLES ICONV
OPTIONS_DEFAULT=ICONV
ICONV_DESC=	Enable iconv character set conversion support

PORTSCOUT=	limitw:1,even

CONFIGURE_ARGS=	--datarootdir=${DATADIR} --docdir=${DOCSDIR}
CONFIGURE_ENV=	PCRE_CONFIG=${LOCALBASE}/bin/pcre-config \
		XAPIAN_CONFIG=${LOCALBASE}/bin/xapian-config
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		libtool localbase perl5 shebangfix tar:xz

MORE_PORTDOCS=	AUTHORS ChangeLog NEWS README TODO
PORTDATA=	*
PORTDOCS=	*
PORTEXAMPLES=	omega.conf

SHEBANG_FILES=	dbi2omega htdig2omega mbox2omega

ICONV_CONFIGURE_ON=	ac_cv_search_iconv=${ICONV_LIB}
ICONV_CONFIGURE_WITH=	iconv
ICONV_USES=		iconv

post-patch:
	@${REINPLACE_CMD} \
		-e '/^dist_sysconf_DATA = /d' \
		-e '/^pkglibbindir = / s| = .*$$| = ${WWWDIR}/cgi-bin|' \
			${WRKSRC}/Makefile.in

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${MORE_PORTDOCS} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
