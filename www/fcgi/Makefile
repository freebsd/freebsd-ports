# New ports collection makefile for:	fcgi-devkit
# Date created:        13 May 1999
# Whom:                kbyanc
#
# $FreeBSD$
#

PORTNAME=	fcgi-devkit
PORTVERSION=	2.2.0
CATEGORIES=	www
MASTER_SITES=	http://www.fastcgi.com/dist/
DISTNAME=	devkit_2.2.0

MAINTAINER=	kbyanc@posi.net

MAN1=		cgi-fcgi.1
MAN3=		FCGI_Accept.3 FCGI_Finish.3 FCGI_SetExitStatus.3 \
		FCGI_StartFilterData.3

USE_PERL5=	yes
GNU_CONFIGURE=	yes

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
.for i in fastcgi-prog-guide fastcgi-whitepaper
	    ${MKDIR} ${PREFIX}/share/doc/${PORTNAME}/$i
	    cd ${WRKSRC}/doc/$i && \
		${INSTALL_DATA} * ${PREFIX}/share/doc/${PORTNAME}/$i
	    @if [ -f ${PREFIX}/share/doc/${PORTNAME}/$i/Makefile ]; then \
		${RM} ${PREFIX}/share/doc/${PORTNAME}/$i/Makefile; \
	    fi
.endfor
.endif

.include <bsd.port.mk>
