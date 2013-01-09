# Created by: janos.mohacsi@bsd.hu
# $FreeBSD$

PORTNAME=	aslookup
PORTVERSION=	0.12
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.bugest.net/software/aslookup/
DISTNAME=	${PORTNAME}-alpha${PORTVERSION}

MAINTAINER=	jmohacsi@bsd.hu
COMMENT=	Tool that searches the sequence of AS numbers

post-patch:
	@${REINPLACE_CMD} -E -e "s|CFLAGS.*=|CFLAGS +=|" \
		-e "s|CC.*=|CC ?=|" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/aslookup ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@if [ ! -d ${PREFIX}/share/doc/aslookup ]; then 	\
		${MKDIR} ${PREFIX}/share/doc/aslookup; fi
	${INSTALL_DATA} ${WRKSRC}/readme-eng.txt ${WRKSRC}/readme-jp.txt   \
		${PREFIX}/share/doc/aslookup
.endif

.include <bsd.port.mk>
