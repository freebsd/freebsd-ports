# Created by: Sergei Kolobov <sergei@kolobov.com>
# $FreeBSD$

PORTNAME=	metalog
PORTVERSION=	3
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Modern syslogd replacement with PCRE support

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpcre.so:devel/pcre

USES=		pkgconfig tar:xz
USE_RC_SUBR=	${PORTNAME}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc

PORTDOCS=	AUTHORS NEWS README

OPTIONS_DEFINE=	DOCS UNICODE

UNICODE_CONFIGURE_WITH=	unicode

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/|${PREFIX}/etc/|' ${WRKSRC}/man/*[58].in

post-install:
	${INSTALL_DATA} ${WRKSRC}/metalog.conf ${STAGEDIR}${PREFIX}/etc/metalog.conf.sample

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
