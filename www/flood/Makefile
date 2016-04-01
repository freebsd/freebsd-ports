# $FreeBSD$

PORTNAME=	flood
PORTVERSION=	0.20041105
PORTREVISION=	8
CATEGORIES=	www
MASTER_SITES=	http://dist.bsdlab.org/
DISTNAME=	httpd-test_20041105052051

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Profile-driven HTTP load tester

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libapr-1.so:devel/apr1

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-apr=${LOCALBASE}/bin/apr-1-config \
		--with-apr-util=${LOCALBASE}/bin/apu-1-config
USES=		autoreconf gmake iconv
WRKSRC=		${WRKDIR}/httpd-test/flood

EX_SCRIPTS=	analyze-relative analyze-relative-ramp
EX_DATA=	flood.dtd relative-averages-time.awk round-robin-dynamic.xml \
		round-robin-example.xml round-robin-keepalive.xml \
		round-robin-relative-reports.xml round-robin-ssl.xml \
		round-robin-timed.xml round-robin.xml

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/flood ${STAGEDIR}${PREFIX}/bin/flood

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for f in ${EX_SCRIPTS}
	@${INSTALL_SCRIPT} ${WRKSRC}/examples/$f ${STAGEDIR}${EXAMPLESDIR}
.endfor
.for f in ${EX_DATA}
	@${INSTALL_DATA} ${WRKSRC}/examples/$f ${STAGEDIR}${EXAMPLESDIR}
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/docbook
	@${INSTALL_DATA} ${WRKSRC}/docs/README ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/docs/docbook/[Mf]* ${STAGEDIR}${DOCSDIR}/docbook

ANONCVS=	cvs -d :pserver:anoncvs@cvs.apache.org:/home/cvspublic

maint-checkout:
	${ANONCVS} co httpd-test/flood

# http://cvs.apache.org/snapshots/httpd-test/

.include <bsd.port.mk>
