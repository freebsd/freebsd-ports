# ports collection makefile for:	mod_v2h
# Date created:				6th May 2002
# Whom:					hikari-chan
#
# $FreeBSD$
#

PORTNAME=	mod_v2h
PORTVERSION=	2.0
CATEGORIES=	www
MASTER_SITES=	http://www.fractal.net/files/
DISTNAME=	mod_v2h

MAINTAINER=	apache@FreeBSD.org
COMMENT=	A mass virtual hosting module for Apache with support

BUILD_DEPENDS=	${LOCALBASE}/sbin/httpd:${PORTSDIR}/www/apache2 \
		${LOCALBASE}/lib/mysql/libmysqlclient.so:${PORTSDIR}/databases/mysql323-client
RUN_DEPENDS=	${LOCALBASE}/sbin/httpd:${PORTSDIR}/www/apache2 \
		${LOCALBASE}/lib/mysql/libmysqlclient.so:${PORTSDIR}/databases/mysql323-client

WRKSRC=		${WRKDIR}/${DISTNAME}-2
USE_REINPLACE=	yes
USE_PERL5_RUN=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CFLAGS=		-fPIC
.endif

post-patch:
	${CP} ${FILESDIR}/add-module ${WRKSRC}
	${CP} ${FILESDIR}/files-Makefile ${WRKSRC}/Makefile
	${REINPLACE_CMD} \
		-e 's,@@PERL@@,${PERL},g' \
		-e 's,@@LOCAL@@,${LOCALBASE},g' \
		${WRKSRC}/Makefile ${WRKSRC}/add-module

post-install:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "===> Stripping ${LOCALBASE}/libexec/apache2/mod_v2h.so"
	@${STRIP_CMD} ${LOCALBASE}/libexec/apache2/mod_v2h.so
	@${ECHO_MSG} ""
	@${ECHO_MSG} "---------------------------------------"
	@${ECHO_MSG} "Remember to check the documentation on:"
	@${ECHO_MSG} "http://www.fractal.net/mod_v2h.tm"
	@${ECHO_MSG} "---------------------------------------"
	@${ECHO_MSG} ""

.include <bsd.port.post.mk>
