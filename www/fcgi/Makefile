# New ports collection makefile for:	fcgi-devkit
# Date created:        13 May 1999
# Whom:                kbyanc
#
# $FreeBSD$
#

PORTNAME=	fcgi
PORTVERSION=	2.4.0
CATEGORIES=	www
MASTER_SITES=	http://www.fastcgi.com/dist/
PKGNAMESUFFIX=	-devkit

MAINTAINER=	kimelto@gmail.com
COMMENT=	FastCGI Development Kit

USE_AUTOTOOLS=	libtool:15
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		cgi-fcgi.1
MAN3=		FCGI_Accept.3 FCGI_Finish.3 FCGI_SetExitStatus.3 \
		FCGI_StartFilterData.3

post-install:
.for y in ${MAN1}
	@${INSTALL_MAN} ${WRKSRC}/doc/${y} ${MANPREFIX}/man/man1
.endfor
.for x in ${MAN3}
	@${INSTALL_MAN} ${WRKSRC}/doc/${x} ${MANPREFIX}/man/man3
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/*.htm* ${WRKSRC}/doc/*.gif \
		${DOCSDIR}
.for i in fastcgi-prog-guide fastcgi-whitepaper
	@${MKDIR} ${DOCSDIR}/${i}
	@${INSTALL_DATA} ${WRKSRC}/doc/${i}/* ${DOCSDIR}/$i
.endfor
.endif

.include <bsd.port.mk>
