# New ports collection makefile for:    mod_sqlinclude
# Date created:				October 25 2001
# Whom:					Anders Nordby <anders@fix.no>
#
# $FreeBSD$

PORTNAME=	mod_sqlinclude
PORTVERSION=	1.2
CATEGORIES=	www
MASTER_SITES=	http://wfmh.org.pl/~carlos/files/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/
DISTNAME=	${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	anders@fix.no

BUILD_DEPENDS=	${APXS}:${PORTSDIR}/www/apache13
LIB_DEPENDS=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client
RUN_DEPENDS=	${APXS}:${PORTSDIR}/www/apache13

APXS?=		${LOCALBASE}/sbin/apxs
DOCS=	CHANGES.txt README.txt TODO.txt

do-build:
	(cd ${WRKSRC} && ${APXS} -c -I${LOCALBASE}/include \
	-L${LOCALBASE}/lib/mysql -lmysqlclient mod_sqlinclude.c)

do-install:
	(cd ${WRKSRC} && ${APXS} -i -A -n 'sqlinclude' mod_sqlinclude.so)
.if !defined(NOPORTDOCS)
	@${INSTALL} -d -m 0755 ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
