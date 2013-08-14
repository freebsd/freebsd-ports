# New ports collection makefile for:	lurker
# Date created:				01 Feb 2011
# Whom:					Kevin Rauwolf <sweetpea-freebsd@tentacle.net>
#
# $FreeBSD$
#

PORTNAME=	lurker
PORTVERSION=	2.3
CATEGORIES=	mail
MASTER_SITES=	SF:0 \
		SF/${PORTNAME}/mimelib/${MIMELIB_VERSION}/:1
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:0 mimelib-${MIMELIB_VERSION}.tar.gz:1
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	sweetpea-freebsd@tentacle.net
COMMENT=	A mailing list archiver

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

MIMELIB_VERSION=	3.1.1
USES=		iconv
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-mimelib-local \
		--with-default-www-dir=${PREFIX}/www/lurker \
		--with-cgi-bin-dir=${PREFIX}/www/lurker

MAN1=		lurker-index.1 lurker-list.1 lurker-params.1 \
		lurker-regenerate.1 lurker-search.1 lurker-prune.1

post-extract:
	@cd ${WRKSRC} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		${DISTDIR}/mimelib-${MIMELIB_VERSION}.tar.gz ${EXTRACT_AFTER_ARGS}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/INSTALL ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/FAQ ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/ChangeLog ${DOCSDIR}
.endif
	@${CHOWN} -R www:www ${PREFIX}/www/lurker
	${INSTALL_DATA} ${WRKSRC}/lurker.conf ${PREFIX}/etc/lurker/lurker.conf.sample
	@if [ ! -f ${PREFIX}/etc/lurker/lurker.conf ]; then \
		${CP} -p ${PREFIX}/etc/lurker/lurker.conf.sample ${PREFIX}/etc/lurker/lurker.conf ; \
	fi
	${INSTALL_DATA} ${WRKSRC}/apache.conf ${PREFIX}/etc/lurker/apache.conf.sample
	@if [ ! -f ${PREFIX}/etc/lurker/apache.conf ]; then \
		${CP} -p ${PREFIX}/etc/lurker/apache.conf.sample ${PREFIX}/etc/lurker/apache.conf ; \
	fi
.include <bsd.port.mk>
