# New ports collection makefile for:	mod_auth_pam
# Date created:				7 April 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	mod_color
PORTVERSION=	0.3
CATEGORIES=	www
# mastersite disappeared in 2001
MASTER_SITES=	# http://www.dimensional.com/~bgiles/${PORTNAME}
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.l

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache module that provides syntax coloring for various languages

MAKE_JOBS_SAFE=  yes

USE_APACHE=	1.3
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

NO_WRKSUBDIR=	yes

do-extract:
	${MKDIR} ${WRKSRC}/
	${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}/

pre-build:
	lex -t -Psyncc ${WRKSRC}/${PORTNAME}.l > ${WRKSRC}/${PORTNAME}.c

.include <bsd.port.mk>
