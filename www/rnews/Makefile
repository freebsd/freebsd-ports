# New ports collection makefile for:	rnews
# Date created:		22 December 2003
# Whom:			Vincent Tantardini <vinc@FreeBSD-fr.org>
#
# $FreeBSD$
#

PORTNAME=	rnews
PORTVERSION=	0.63
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A server-side rss aggregator written in php with mysql

USE_MYSQL=	yes

NO_BUILD=	yes
MYPORTDOCS=	CHANGELOG INSTALL LICENSE README magpierss/AUTHORS \
		magpierss/CHANGES magpierss/ChangeLog magpierss/INSTALL \
		magpierss/NEWS magpierss/README magpierss/TROUBLESHOOTING

OPTIONS=	PHP3 "use RNEWS with PHP3 (Default is PHP4)" off

.include <bsd.port.pre.mk>

.if defined(WITH_PHP3)
RUN_DEPENDS+=	${LOCALBASE}/libexec/apache/libphp3.so:${PORTSDIR}/www/mod_php3
.else
RUN_DEPENDS+=	${LOCALBASE}/libexec/apache/libphp4.so:${PORTSDIR}/www/mod_php4
.endif

post-patch:
	@${FIND} ${WRKSRC} -name CVS -type d | ${XARGS} ${RM} -fr

do-install:
	@${MKDIR} ${PREFIX}/www/rnews
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/magpierss
.   for FILE in ${MYPORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}/${FILE}
.   endfor
.endif
	${MKDIR} ${PREFIX}/www/rnews
	${MKDIR} ${PREFIX}/www/rnews/magpierss-0.5.2
	cd ${PREFIX}/www/rnews && ${LN} -s magpierss-0.5.2 magpierss
	${MKDIR} ${PREFIX}/www/rnews/magpierss/cache
	${INSTALL_DATA} -v ${WRKSRC}/*.png ${PREFIX}/www/rnews
	${INSTALL_DATA} -v ${WRKSRC}/*.php ${PREFIX}/www/rnews
	${INSTALL_DATA} -v ${WRKSRC}/*.inc ${PREFIX}/www/rnews
	${INSTALL_DATA} -v ${WRKSRC}/magpierss/*.inc ${PREFIX}/www/rnews/magpierss
	${INSTALL_DATA} -v ${WRKSRC}/magpierss/cookbook ${PREFIX}/www/rnews/magpierss
	${CP} -Rv ${WRKSRC}/magpierss/extlib ${PREFIX}/www/rnews/magpierss
	${CP} -Rv ${WRKSRC}/magpierss/htdocs ${PREFIX}/www/rnews/magpierss
	${CP} -Rv ${WRKSRC}/magpierss/scripts ${PREFIX}/www/rnews/magpierss
	@${CHOWN} ${WWWOWN}:${WWWGRP} ${PREFIX}/www/rnews/magpierss/cache
	@${SED} "s,%%PREFIX%%,${PREFIX},g" ${PKGMESSAGE}

.include <bsd.port.post.mk>
