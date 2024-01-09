PORTNAME=	gotmail
PORTVERSION=	0.9.0
PORTREVISION=	4
CATEGORIES=	mail perl5
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Script to fetch mail from a Hotmail or MSN mailbox
WWW=		https://sourceforge.net/projects/gotmail/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	curl:ftp/curl \
		p5-URI>=0:net/p5-URI

USES=		perl5 shebangfix
SHEBANG_FILES=	gotmail
NO_ARCH=	yes

PORTDOCS=	ChangeLog README sample.gotmailrc
PLIST_FILES=	bin/gotmail share/man/man1/gotmail.1.gz

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.man \
		${STAGEDIR}${PREFIX}/share/man/man1/${PORTNAME}.1
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
