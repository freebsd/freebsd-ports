# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	stowES
PORTVERSION=	0.5.6
CATEGORIES=	sysutils
MASTER_SITES=	http://os.inf.tu-dresden.de/~adam/stowES/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Stow enhancement script

LICENSE=	GPLv2

RUN_DEPENDS=	stow:${PORTSDIR}/sysutils/stow

USES=		perl5
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=		${PORTNAME}.1
PORTDOCS=	AUTHORS ChangeLog NEWS README TODO \
		${PORTNAME}.html ${PORTNAME}.pod ${PORTNAME}.txt
PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e "s|'md5sum',|'md5',|" ${WRKSRC}/${PORTNAME}.in

.include <bsd.port.options.mk>

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MANPREFIX}/man/man1
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_SCRIPT} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
