# New ports collection makefile for:	coccigrep
# Date created:		2012-04-14
# Whom:			Pawel Pekala <pawel@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	coccigrep
PORTVERSION=	1.8
CATEGORIES=	textproc
MASTER_SITES=	http://home.regit.org/wp-content/uploads/2011/08/

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Semantic grep for the C language

LICENSE=	GPLv3

RUN_DEPENDS=	${LOCALBASE}/bin/spatch:${PORTSDIR}/devel/coccinelle

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install
MANCOMPRESSED=	no

MAN1=		coccigrep.1

post-install:
	${INSTALL_MAN} ${WRKSRC}/coccigrep.1 ${MANPREFIX}/man/man1
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/editors/cocci-grep.el ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/editors/cocci-grep.vim ${DATADIR}

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.rst ${DOCSDIR}
.endif

.include <bsd.port.mk>
