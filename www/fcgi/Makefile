# Created by: kbyanc
# $FreeBSD$

PORTNAME=	fcgi
PORTVERSION=	2.4.0
CATEGORIES=	www
MASTER_SITES=	http://www.fastcgi.com/dist/
PKGNAMESUFFIX=	-devkit

MAINTAINER=	jlaffaye@FreeBSD.org
COMMENT=	FastCGI Development Kit

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

MAN1=		cgi-fcgi.1
MAN3=		FCGI_Accept.3 FCGI_Finish.3 FCGI_SetExitStatus.3 \
		FCGI_StartFilterData.3

NO_STAGE=	yes
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
