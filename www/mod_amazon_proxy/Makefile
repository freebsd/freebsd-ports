# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mod_amazon_proxy
PORTVERSION=	20100913
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	LOCAL/tota/${PORTNAME}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Amazon Auth Proxy for Product Advertising API

LIB_DEPENDS=	libapreq2.so:www/libapreq2

USES=		apache:2.2+
AP_FAST_BUILD=	yes
AP_LIB=	${LOCALBASE}/lib -lcrypto

CONFFILE=	httpd-amazon-proxy.conf
CONFDIR=	${PREFIX}/${APACHEETCDIR}/Includes

PORTDOCS=	README
PORTEXAMPLES=	rpaproxy.yaml

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e 's|modules|${APACHEMODDIR}|' ${WRKSRC}/${CONFFILE}.sample

post-install:
	@${MKDIR} ${STAGEDIR}${CONFDIR}
	${INSTALL_DATA} ${WRKSRC}/${CONFFILE}.sample ${STAGEDIR}${CONFDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}

x-generate-tarball:
	${SETENV} ${FETCH_ENV} ${FETCH_BINARY} -m -o ${PORTNAME}.tar.gz \
		https://github.com/machu/mod_amazon_proxy/tarball/master
	target=`${TAR} -tvf ${PORTNAME}.tar.gz | head -n 1`; \
	dir=`${ECHO} $${target} | ${AWK} '{print $$9}' | ${SED} -e 's|/$$||'`; \
	year=`${ECHO} $${target} | ${AWK} '{print $$8}'`; \
	month=`${ECHO} $${target} | ${AWK} '{print $$6}'`; \
	day=`${ECHO} $${target} | ${AWK} '{print $$7}'`; \
	date=`date -j -f "%B %d %Y" "$${month} $${day} $${year}" +"%Y%m%d"`; \
	${TAR} -zxf ${PORTNAME}.tar.gz; \
	${RM} ${PORTNAME}.tar.gz; \
	${RM} $${dir}/Makefile; \
	${RM} $${dir}/modules.mk; \
	${MV} $${dir} ${PORTNAME}-$${date}; \
	${TAR} -zcf ${PORTNAME}-$${date}.tar.gz ${PORTNAME}-$${date}; \
	${RM} -r ${PORTNAME}-$${date}

.include <bsd.port.mk>
