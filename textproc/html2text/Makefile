PORTNAME=	html2text
PORTVERSION=	2.2.3
PORTEPOCH=	1
CATEGORIES=	textproc
MASTER_SITES= 	https://github.com/grobian/${PORTNAME}/releases/download/v${PORTVERSION}/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Converts HTML documents into plain text
WWW=		https://gitlab.com/grobian/html2text

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

PLIST_FILES=	bin/html2text share/man/man1/html2text.1.gz share/man/man5/html2textrc.5.gz

CONFLICTS=	py*-html2text py*-html2text2018 # bin/html2text

.include <bsd.port.mk>
