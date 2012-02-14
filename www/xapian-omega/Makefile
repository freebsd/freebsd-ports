# New ports collection makefile for:	xapian-omega
# Date created:		05 Jul 2008
# Whom:			Henrik Brix Andersen <brix@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xapian-omega
PORTVERSION=	1.2.8
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://oligarchy.co.uk/xapian/${PORTVERSION}/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	CGI search application built on Xapian

LICENSE=	GPLv2

LIB_DEPENDS=	pcre.1:${PORTSDIR}/devel/pcre \
		xapian.26:${PORTSDIR}/databases/xapian-core

OPTIONS=	ICONV	"Enable iconv character set conversion support" on

CONFIGURE_ENV=	PCRE_CONFIG=${LOCALBASE}/bin/pcre-config \
		XAPIAN_CONFIG=${LOCALBASE}/bin/xapian-config
CPPFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes
USE_PERL5=	yes

MAN1=		omindex.1 scriptindex.1
MORE_PORTDOCS=	AUTHORS ChangeLog NEWS README TODO
PORTDOCS=	cgiparams.html index.html omegascript.html overview.html \
		quickstart.html scriptindex.html termprefixes.html \
		${MORE_PORTDOCS}
PORTEXAMPLES=	omega.conf

.include <bsd.port.options.mk>

.if defined(WITH_ICONV)
USE_ICONV=	yes
CONFIGURE_ARGS+=--with-iconv
.else
CONFIGURE_ARGS+=--without-iconv
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e '/^dist_sysconf_DATA = /d' \
		-e '/^pkglibbindir = / s| = .*$$| = ${WWWDIR}/cgi-bin|' \
			${WRKSRC}/Makefile.in
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/^SUBDIRS = / s| docs||' ${WRKSRC}/Makefile.in
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${MORE_PORTDOCS} ${DOCSDIR}/
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTEXAMPLES} ${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
