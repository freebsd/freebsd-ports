# ex:ts=8
# New ports collection Makefile for: nmzmail
# Date created:		7 January 2005
# Whom:			fernan@iib.unsam.edu.ar
#
# $FreeBSD$
#

PORTNAME=	nmzmail
PORTVERSION=	0.1.2
CATEGORIES=	mail
MASTER_SITES=	http://www.ecademix.com/JohannesHofmann/

MAINTAINER=	fernan@iib.unsam.edu.ar
COMMENT=	Fast mail searching for mutt

RUN_DEPENDS=	namazu:${PORTSDIR}/databases/namazu2 \
		mutt:${PORTSDIR}/mail/mutt

USE_GMAKE=	yes
ALL_TARGET=	# empty
PLIST_FILES=	bin/nmzmail
PORTDOCS=	README

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500018
LIB_DEPENDS+=	readline.5:${PORTSDIR}/devel/readline
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nmzmail ${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
