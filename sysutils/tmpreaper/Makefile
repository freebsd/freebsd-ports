PORTNAME=	tmpreaper
DISTVERSION=	1.6.17
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	DEBIAN
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Cleans up files in directories based on their age
WWW=		https://packages.debian.org/sid/tmpreaper

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=				autoreconf cpe
CPE_VENDOR=			debian
GNU_CONFIGURE=			yes

INSTALL_TARGET=	install-strip

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	sbin/tmpreaper \
		share/man/man8/tmpreaper.8.gz
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
