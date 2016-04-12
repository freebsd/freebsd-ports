# Created by: Tim Vanderhoek <ac199@freenet.hamilton.on.ca>
# $FreeBSD$

PORTNAME=	plor
PORTVERSION=	0.3.3
PORTREVISION=	1
CATEGORIES=	news
MASTER_SITES=	SUNSITE/system/bbs/mail

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Alpha-release reader for reading SOUP and QWK packets

RUN_DEPENDS=	zip:archivers/zip

GNU_CONFIGURE=	yes
USES=		gmake perl5

DOCFILES=	../AUTHORS ../NEWS TODO plor-1.html plor-2.html \
		plor.html plor.txt

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/plor
.for f in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/docs/${f} ${STAGEDIR}${PREFIX}/share/doc/plor
.endfor
	${INSTALL_MAN} ${FILESDIR}/plor.1 ${STAGEDIR}${PREFIX}/man/man1/plor.1
	${PERL} -pi -e '$$a = '\''${PREFIX}/share/doc/plor/'\''; $$a =~ s/([^\w\/])/\\$$1/g; s/FUNKYTOKENHERE/$$a/' ${STAGEDIR}${PREFIX}/man/man1/plor.1

.include <bsd.port.mk>
