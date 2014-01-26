# Created by: Anders Nordby <anders@FreeBSD.org>
# $FreeBSD$

PORTNAME=	darkstat
PORTVERSION=	3.0.718
CATEGORIES=	net-mgmt
MASTER_SITES=	http://unix4lyfe.org/darkstat/

MAINTAINER=	emikulic@gmail.com
COMMENT=	Network statistics gatherer and reporter

USE_RC_SUBR=	darkstat

USE_BZIP2=	yes
GNU_CONFIGURE=	yes

PORTDOCS=	AUTHORS INSTALL README
PLIST_FILES=	sbin/darkstat man/man8/darkstat.8.gz

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
