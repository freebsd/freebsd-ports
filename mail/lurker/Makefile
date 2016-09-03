# $FreeBSD$

PORTNAME=	lurker
PORTVERSION=	2.3
PORTREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	SF:0 \
		SF/${PORTNAME}/mimelib/${MIMELIB_VERSION}/:1
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:0 mimelib-${MIMELIB_VERSION}.tar.gz:1
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mailing list archiver

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

MIMELIB_VERSION=	3.1.1

USES=		iconv localbase
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-mimelib-local \
		--with-default-www-dir=${PREFIX}/www/lurker \
		--with-cgi-bin-dir=${PREFIX}/www/lurker
PLIST_SUB=	WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"

OPTIONS_DEFINE=	DOCS

post-extract:
	@cd ${WRKSRC} && ${TAR} ${EXTRACT_BEFORE_ARGS} \
		${DISTDIR}/mimelib-${MIMELIB_VERSION}.tar.gz ${EXTRACT_AFTER_ARGS}

post-install:
	${INSTALL_DATA} ${WRKSRC}/lurker.conf ${STAGEDIR}${PREFIX}/etc/lurker/lurker.conf.sample
	${INSTALL_DATA} ${WRKSRC}/apache.conf ${STAGEDIR}${PREFIX}/etc/lurker/apache.conf.sample

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/FAQ ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
