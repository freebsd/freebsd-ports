# Created by: Henrik Brix Andersen <brix@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xapian-omega
PORTVERSION=	1.2.15
CATEGORIES=	www
MASTER_SITES=	http://oligarchy.co.uk/xapian/${PORTVERSION}/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	CGI search application built on Xapian

LICENSE=	GPLv2

LIB_DEPENDS=	pcre:${PORTSDIR}/devel/pcre \
		xapian:${PORTSDIR}/databases/xapian-core

OPTIONS_DEFINE=	DOCS EXAMPLES ICONV
OPTIONS_DEFAULT=ICONV
ICONV_DESC=	Enable iconv character set conversion support

PORTSCOUT=	limitw:1,even

CONFIGURE_ENV=	PCRE_CONFIG=${LOCALBASE}/bin/pcre-config \
		XAPIAN_CONFIG=${LOCALBASE}/bin/xapian-config
CPPFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes
USES=		perl5

MAN1=		omindex.1 scriptindex.1
MORE_PORTDOCS=	AUTHORS ChangeLog NEWS README TODO
PORTDOCS=	cgiparams.html index.html omegascript.html overview.html \
		quickstart.html scriptindex.html termprefixes.html \
		${MORE_PORTDOCS}
PORTEXAMPLES=	omega.conf

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MICONV}
USES+=		iconv
CONFIGURE_ARGS+=--with-iconv
.else
CONFIGURE_ARGS+=--without-iconv
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e '/^dist_sysconf_DATA = /d' \
		-e '/^pkglibbindir = / s| = .*$$| = ${WWWDIR}/cgi-bin|' \
			${WRKSRC}/Makefile.in
.if !${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e '/^SUBDIRS = / s| docs||' ${WRKSRC}/Makefile.in
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${MORE_PORTDOCS} ${DOCSDIR}/
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTEXAMPLES} ${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
