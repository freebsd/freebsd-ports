# New ports collection makefile for:	webjob
# Date created:		20 August 2002
# Whom:			Klayton Monroe <klm@ir.exodus.net>
#
# $FreeBSD$
#

PORTNAME=	webjob
PORTVERSION=	1.2.3
CATEGORIES=	sysutils security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	webjob
EXTRACT_SUFX=	.tgz

MAINTAINER=	klm@ir.exodus.net
COMMENT=	Download and execute a program over HTTP/HTTPS

MAN1=		webjob.1

GNU_CONFIGURE=	YES

.if defined(WITHOUT_SSL)
CONFIGURE_ARGS=	--without-ssl
.else
USE_OPENSSL=	YES
CONFIGURE_ARGS=	--with-ssl=${OPENSSLBASE}
.endif

pre-build:
	@${MV} ${WRKSRC}/etc/webjob.cfg ${WRKSRC}/etc/webjob.cfg.sample
	@${MV} ${WRKSRC}/etc/Makefile ${WRKSRC}/etc/Makefile.orig
	@${SED} 's/webjob.cfg/webjob.cfg.sample/g' ${WRKSRC}/etc/Makefile.orig > ${WRKSRC}/etc/Makefile

.include <bsd.port.mk>
