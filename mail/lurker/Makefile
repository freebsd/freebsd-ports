# $FreeBSD$

PORTNAME=	lurker
PORTVERSION=	2.3
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	SF:0 \
		SF/${PORTNAME}/mimelib/${MIMELIB_VERSION}/:1
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:0 mimelib-${MIMELIB_VERSION}.tar.gz:1
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	sweetpea-freebsd@tentacle.net
COMMENT=	Mailing list archiver

LICENSE=	GPLv2

MIMELIB_VERSION=	3.1.1
USES=		iconv
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-mimelib-local \
		--with-default-www-dir=${PREFIX}/www/lurker \
		--with-cgi-bin-dir=${PREFIX}/www/lurker

OPTIONS_DEFINE=	DOCS

post-extract:
	@cd ${WRKSRC} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		${DISTDIR}/mimelib-${MIMELIB_VERSION}.tar.gz ${EXTRACT_AFTER_ARGS}

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/INSTALL ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/FAQ ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/ChangeLog ${STAGEDIR}${DOCSDIR}
	@${CHOWN} -R www:www ${STAGEDIR}${PREFIX}/www/lurker
	${INSTALL_DATA} ${WRKSRC}/lurker.conf ${STAGEDIR}${PREFIX}/etc/lurker/lurker.conf.sample
	${INSTALL_DATA} ${WRKSRC}/apache.conf ${STAGEDIR}${PREFIX}/etc/lurker/apache.conf.sample

.include <bsd.port.mk>
