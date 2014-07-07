# Created by: kbyanc
# $FreeBSD$

PORTNAME=	fcgi
PORTVERSION=	2.4.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.fastcgi.com/dist/ \
		http://www.skysmurf.nl/comp/FreeBSD/distfiles/
PKGNAMESUFFIX=	-devkit

MAINTAINER=	freebsd@skysmurf.nl
COMMENT=	FastCGI Development Kit

LICENSE_FILE=	LICENSE.TERMS

USES=		libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

PORTDOCS=	*.htm *.html *.gif fastcgi-prog-guide/* fastcgi-whitepaper/*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libfcgi.so.0.0.0
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libfcgi++.so.0.0.0
	${INSTALL_MAN} ${WRKSRC}/doc/*.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/*.3 ${STAGEDIR}${MANPREFIX}/man/man3
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
	@${RM} ${STAGEDIR}${DOCSDIR}/*.[13]
.endif

.include <bsd.port.mk>
