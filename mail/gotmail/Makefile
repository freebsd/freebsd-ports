# Created by: Christopher Elkins <chrise@scardini.com>
# $FreeBSD$

PORTNAME=	gotmail
PORTVERSION=	0.9.0
PORTREVISION=	2
CATEGORIES=	mail perl5
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A script to fetch mail from a Hotmail or MSN mailbox

RUN_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-Net>=0:${PORTSDIR}/net/p5-Net

USES=		perl5 shebangfix

PLIST_FILES=	bin/gotmail man/man1/gotmail.1.gz
SHEBANG_FILES=	gotmail
PORTDOCS=	ChangeLog README sample.gotmailrc

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.man \
		${STAGEDIR}${MANPREFIX}/man/man1/${PORTNAME}.1
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
