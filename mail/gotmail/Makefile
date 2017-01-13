# Created by: Christopher Elkins <chrise@scardini.com>
# $FreeBSD$

PORTNAME=	gotmail
PORTVERSION=	0.9.0
PORTREVISION=	2
CATEGORIES=	mail perl5
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Script to fetch mail from a Hotmail or MSN mailbox

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	curl:ftp/curl \
		p5-URI>=0:net/p5-URI \
		p5-Net>=0:net/p5-Net

USES=		perl5 shebangfix
SHEBANG_FILES=	gotmail
NO_ARCH=	yes

PORTDOCS=	ChangeLog README sample.gotmailrc
PLIST_FILES=	bin/gotmail man/man1/gotmail.1.gz

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1100077
# chmod -R bug
post-extract:
	@${CHMOD} 755 ${WRKSRC}
.endif

do-install:
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.man \
		${STAGEDIR}${MANPREFIX}/man/man1/${PORTNAME}.1
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.post.mk>
