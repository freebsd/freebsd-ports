# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	stowES
PORTVERSION=	0.5.7
CATEGORIES=	sysutils
MASTER_SITES=	http://os.inf.tu-dresden.de/~adam/stowES/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Stow enhancement script

LICENSE=	GPLv2

RUN_DEPENDS=	stow:${PORTSDIR}/sysutils/stow

OPTIONS_DEFINE=	DOCS

USES=		gmake perl5
GNU_CONFIGURE=	yes

PORTDOCS=	AUTHORS ChangeLog NEWS README TODO \
		${PORTNAME}.html ${PORTNAME}.pod ${PORTNAME}.txt
PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e "s|'md5sum',|'md5',|" ${WRKSRC}/${PORTNAME}.in

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_SCRIPT} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
