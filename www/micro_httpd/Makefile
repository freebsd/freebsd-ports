# New ports collection makefile for:	micro_httpd
# Date created:				13 Jul 2001
# Whom:					Kim Scarborough <user@unknown.nu>
#
# $FreeBSD$
#

PORTNAME=	micro_httpd
PORTVERSION=	2000.12.15
CATEGORIES=	www
MASTER_SITES=	http://www.acme.com/software/micro_httpd/ \
		http://www.unknown.nu/ports/
DISTNAME=	${PORTNAME}_15dec00

MAINTAINER=	user@unknown.nu
COMMENT=	An extremely small web server

USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
MAN8=		micro_httpd.8
PLIST_FILES=	sbin/micro_httpd

post-patch:
	@${REINPLACE_CMD} -e "s:/usr/local/sbin:${PREFIX}/sbin:g; \
		s:/usr/local/man/man8:${MAN8PREFIX}/man/man8:g; \
		s:^(CC|CFLAGS) =.+::g;" \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e "s/^.TH micro_httpd 1/.TH micro_httpd 8/g" \
		${WRKSRC}/micro_httpd.8

.include <bsd.port.mk>
