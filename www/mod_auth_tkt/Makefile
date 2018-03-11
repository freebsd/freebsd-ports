# $FreeBSD$

PORTNAME=	mod_auth_tkt
PORTVERSION=	2.1.0
PORTREVISION=	3
CATEGORIES=	www
MASTER_SITES=	LOCAL/kuriyama \
		http://www.openfusion.com.au/labs/dist/mod_auth_tkt/

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Lightweight single-sign-on authentication module for apache

USES=		apache:2.2+ shebangfix
SHEBANG_FILES=	../cgi/login.cgi \
		../cgi/logout.cgi
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src
PATCH_WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}
PATCH_STRIP=	-p1
AP_FAST_BUILD=	yes
SRC_FILE=	${PORTNAME}.c sha2.c
AP_EXTRAS=	-DAPACHE22

OPTIONS_DEFINE=	QUERY_SEP DOCS EXAMPLES
QUERY_SEP_DESC=	Experimental TKTAuthQuerySeparator directive
OPTIONS_DEFAULT=QUERY_SEP

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MQUERY_SEP}
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-query-separator
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|.usr/share/man|${STAGEDIR}${PREFIX}/man|' ${WRKSRC}/../Makedefs

post-build:
	cd ${WRKSRC}/../doc; ${MAKE} all

post-install:
	cd ${WRKSRC}/../doc; ${MAKE} ${.TARGET:S/post-//}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/cgi/Apache ${STAGEDIR}${EXAMPLESDIR}/conf
.for i in cgi/AuthTktConfig.pm cgi/Apache/AuthTkt.pm cgi/tkt.css \
	conf/02_auth_tkt.conf conf/auth_tkt_cgi.conf
	${INSTALL_DATA} ${WRKSRC}/../${i} ${STAGEDIR}${EXAMPLESDIR}/${i}
.endfor
.for i in logout.cgi login.cgi
	${INSTALL_SCRIPT} ${WRKSRC}/../cgi/${i} ${STAGEDIR}${EXAMPLESDIR}/cgi/${i}
.endfor
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../README ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
