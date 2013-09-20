# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mod_amazon_proxy
PORTVERSION=	20100913
CATEGORIES=	www
MASTER_SITES=	LOCAL
MASTER_SITE_SUBDIR=	tota/${PORTNAME}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Amazon Auth Proxy for Product Advertising API

LIB_DEPENDS=	apreq2:${PORTSDIR}/www/libapreq2

USE_APACHE=	22

CONFFILE=	httpd-amazon-proxy.conf
CONFDIR=	${PREFIX}/${APACHEETCDIR}/Includes

PORTDOCS=	README
PORTEXAMPLES=	rpaproxy.yaml

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|modules|${APACHEMODDIR}|' ${WRKSRC}/${CONFFILE}.sample

do-build:
	@${APXS} -c ${BUILD_WRKSRC}/${PORTNAME}.c

do-install:
	@${APXS} -i ${INSTALL_WRKSRC}/${PORTNAME}.la
	${INSTALL_DATA} ${WRKSRC}/${CONFFILE}.sample ${CONFDIR}
	@if [ ! -f ${CONFDIR}/${CONFFILE} ]; then \
		${CP} -p ${CONFDIR}/${CONFFILE}.sample ${CONFDIR}/${CONFFILE}; \
	fi
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTEXAMPLES} ${EXAMPLESDIR}
.endif

x-generate-tarball:
	${SETENV} ${FETCH_ENV} ${FETCH_BINARY} -m -o ${PORTNAME}.tar.gz \
		https://github.com/machu/mod_amazon_proxy/tarball/master
	target=`${TAR} -tvf ${PORTNAME}.tar.gz | head -n 1`; \
	dir=`${ECHO} $${target} | ${AWK} '{print $$9}' | ${SED} -e 's|/$$||'`; \
	year=`${ECHO} $${target} | ${AWK} '{print $$8}`; \
	month=`${ECHO} $${target} | ${AWK} '{print $$6}`; \
	day=`${ECHO} $${target} | ${AWK} '{print $$7}`; \
	date=`date -j -f "%B %d %Y" "$${month} $${day} $${year}" +"%Y%m%d"`; \
	${TAR} -zxf ${PORTNAME}.tar.gz; \
	${RM} ${PORTNAME}.tar.gz; \
	${RM} $${dir}/Makefile; \
	${RM} $${dir}/modules.mk; \
	${MV} $${dir} ${PORTNAME}-$${date}; \
	${TAR} -zcf ${PORTNAME}-$${date}.tar.gz ${PORTNAME}-$${date}; \
	${RM} -r ${PORTNAME}-$${date}

.include <bsd.port.mk>
