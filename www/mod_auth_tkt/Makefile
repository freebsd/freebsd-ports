# $FreeBSD$

PORTNAME=	mod_auth_tkt
PORTVERSION=	2.1.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://www.openfusion.com.au/labs/dist/mod_auth_tkt/
MASTER_SITE_SUBDIR=	kuriyama

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Lightweight single-sign-on authentication module for apache

USE_APACHE=	22
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src
PATCH_WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}
PATCH_STRIP=	-p1
AP_FAST_BUILD=	yes
SRC_FILE=	${PORTNAME}.c sha2.c
AP_EXTRAS=	-DAPACHE22

MAN3=	mod_auth_tkt.3

OPTIONS_DEFINE=	QUERY_SEP
QUERY_SEP_DESC=	Experimental TKTAuthQuerySeparator directive
OPTIONS_DEFAULT=QUERY_SEP

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MQUERY_SEP}
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-query-separator
.endif

post-patch:
	${REINPLACE_CMD} -e 's|.usr/share/man|${PREFIX}/man|' ${WRKSRC}/../Makedefs

post-build:
	cd ${WRKSRC}/../doc; ${MAKE} all

post-install:
	cd ${WRKSRC}/../doc; ${MAKE} ${.TARGET:S/post-//}
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}/cgi/Apache ${EXAMPLESDIR}/conf
.for i in cgi/AuthTktConfig.pm cgi/Apache/AuthTkt.pm cgi/tkt.css \
	conf/02_auth_tkt.conf conf/auth_tkt_cgi.conf
	${INSTALL_DATA} ${WRKSRC}/../${i} ${EXAMPLESDIR}/${i}
.endfor
.for i in logout.cgi login.cgi
	${INSTALL_SCRIPT} ${WRKSRC}/../cgi/${i} ${EXAMPLESDIR}/cgi/${i}
.endfor
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../README ${DOCSDIR}/
.endif

.include <bsd.port.mk>
