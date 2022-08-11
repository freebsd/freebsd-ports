PORTNAME=	code2html
PORTVERSION=	0.9.1
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	SF \
		http://www.palfrader.org/code2html/all/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sourcecode to HTML converter

NO_BUILD=	yes
USES=		perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	code2html

PLIST_FILES=	bin/code2html man/man1/code2html.1.gz

do-configure:
	@${REINPLACE_CMD} \
		-e 's|/usr/bin/bzip2|${BZIP2_CMD}|' \
		-e 's|/bin/gzip|/usr/bin/gzip|' \
		-e 's|/etc/|${PREFIX}/etc/|' \
		${WRKSRC}/code2html
	@${REINPLACE_CMD} -e 's|/etc/|${PREFIX}/etc/|' \
		${WRKSRC}/code2html.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/code2html ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/code2html.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
