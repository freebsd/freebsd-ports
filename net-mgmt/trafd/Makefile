# New ports collection makefile for:	trafd
# Version required:	3.0
# Date created:		22 January 2000
# Whom:			Michael Vasilenko <acid@stu.cn.ua>
#
# $FreeBSD$
#

DISTNAME=	trafd-3.0
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.riss-telecom.ru/pub/dev/trafd/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/bpft
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/bpft/README
.endif

.include <bsd.port.mk>
