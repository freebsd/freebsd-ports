# ex:ts=8
# New ports collection Makefile for: nmzmail
# Date created:		7 January 2005
# Whom:			fernan@iib.unsam.edu.ar
#
# $FreeBSD$
#

PORTNAME=	nmzmail
PORTVERSION=	0.1.3
CATEGORIES=	mail
MASTER_SITES=	http://www.ecademix.com/JohannesHofmann/

MAINTAINER=	fernan@iib.unsam.edu.ar
COMMENT=	Fast mail searching for mutt

RUN_DEPENDS=	namazu:${PORTSDIR}/databases/namazu2 \
		mutt:${PORTSDIR}/mail/mutt

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GMAKE=	yes

PLIST_FILES=	bin/nmzmail
PORTDOCS=	README	NEWS

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500018
LIB_DEPENDS+=	readline.5:${PORTSDIR}/devel/readline
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	for f in ${PORTDOCS}; do \
	${INSTALL_DATA} ${WRKSRC}/$$f ${DOCSDIR}; \
	done
.endif

.include <bsd.port.post.mk>
