PORTNAME=	renattach
PORTVERSION=	1.2.4
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://www.pc-tools.net/files/unix/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Rename or remove certain attachments or kill entire messages
WWW=		http://www.pc-tools.net/unix/renattach/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

PORTDOCS=	AUTHORS ChangeLog INSTALL NEWS README
PLIST_FILES=	bin/renattach \
		"@sample etc/renattach.conf.sample" \
		share/man/man1/renattach.1.gz

OPTIONS_DEFINE=	DOCS

post-extract:
	@${RM} ${WRKSRC}/src/getopt*

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.ex \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
