# Created by: kbyanc
# $FreeBSD$

PORTNAME=	fcgi
PORTVERSION=	2.4.0
PORTREVISION=	5
CATEGORIES=	www
MASTER_SITES=	LOCAL/adamw
PKGNAMESUFFIX=	-devkit

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	FastCGI Development Kit

LICENSE=	Open_Market_FastCGI_license
LICENSE_NAME=	Open Market FastCGI license
LICENSE_FILE=	${WRKSRC}/LICENSE.TERMS
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		cpe libtool
CPE_VENDOR=	fastcgi

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libfcgi.so.0.0.0
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libfcgi++.so.0.0.0

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/*.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/*.3 ${STAGEDIR}${MANPREFIX}/man/man3
	(cd ${WRKSRC}/doc && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} "! -name *\.[13]")

.include <bsd.port.mk>
