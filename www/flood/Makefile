# New ports collection makefile for:	flood
# Date created:		8 Jan 2003
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	flood
PORTVERSION=	0.20031002
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	kuriyama
DISTNAME=	${PORTNAME}-20031002

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Profile-driven HTTP load tester

LIB_DEPENDS=	expat.4:${PORTSDIR}/textproc/expat2 \
		iconv.3:${PORTSDIR}/converters/libiconv \
		apr-0.9:${PORTSDIR}/devel/apr

USE_AUTOCONF=	yes
WANT_AUTOCONF_VER=	253
CONFIGURE_ARGS=	--disable-shared
CONFIGURE_ENV=	LDFLAGS="-L${PREFIX}/lib"
USE_GMAKE=	yes

EX_SCRIPTS=	analyze-relative analyze-relative-ramp
EX_DATA=	flood.dtd relative-averages-time.awk round-robin-dynamic.xml \
		round-robin-example.xml round-robin-keepalive.xml \
		round-robin-relative-reports.xml round-robin-ssl.xml \
		round-robin-timed.xml round-robin.xml

post-install:
	@${MKDIR} ${EXAMPLESDIR}
.for f in ${EX_SCRIPTS}
	@${INSTALL_SCRIPT} ${WRKSRC}/examples/$f ${EXAMPLESDIR}
.endfor
.for f in ${EX_DATA}
	@${INSTALL_DATA} ${WRKSRC}/examples/$f ${EXAMPLESDIR}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/docbook
	@${INSTALL_DATA} ${WRKSRC}/docs/README ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/docs/docbook/* ${DOCSDIR}/docbook
.endif

.include <bsd.port.mk>
