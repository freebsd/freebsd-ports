# New ports collection makefile for:	squidclam
# Date created:		2005-06-26
# Whom:			Alexander Novitsky <alecn2002@yandex.ru>
#
# $FreeBSD$
#

PORTNAME=	squidclam
PORTVERSION=	0.11
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	alecn2002@yandex.ru
COMMENT=	Bridge betwean ClamAV antivirus software and Squid caching proxy

BUILD_DEPENDS=	${LOCALBASE}/bin/clamscan:${PORTSDIR}/security/clamav	\
		${LOCALBASE}/bin/curl:${PORTSDIR}/ftp/curl
RUN_DEPENDS=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
NO_INSTALL_MANPAGES=	yes

PORTDOCS=	README Changelog

SUB_FILES=	pkg-message

PLIST_FILES=	bin/squidclam %%EXAMPLESDIR%%/squidclam.conf
PLIST_DIRS=	%%EXAMPLESDIR%%

.include <bsd.port.pre.mk>
post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
			  -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/$f ${DOCSDIR}/$f
.endfor
.endif
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sample.conf ${EXAMPLESDIR}/${PORTNAME}.conf

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
