# ex:ts=8
# New ports collection makefile for:	stowES
# Date created:			Mar 17, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	stowES
PORTVERSION=	0.5.5
CATEGORIES=	sysutils
MASTER_SITES=	http://os.inf.tu-dresden.de/~adam/stowES/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	stow Enhancement Script

RUN_DEPENDS=	stow:${PORTSDIR}/sysutils/stow

USE_PERL5=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=		${PORTNAME}.1
PORTDOCS=	AUTHORS ChangeLog NEWS README TODO \
		${PORTNAME}.html ${PORTNAME}.pod ${PORTNAME}.txt
PLIST_FILES=	bin/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e "s|'md5sum',|'md5',|" ${WRKSRC}/${PORTNAME}.in

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_SCRIPT} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
