# New ports collection makefile for:	micq
# Date created:				11 Oct 1998
# Whom:					mph
#
# $FreeBSD$
#

PORTNAME=	micq
PORTVERSION=	0.4.9.4
CATEGORIES=	net
MASTER_SITES=	http://micq.org/source/ \
		http://micq.alpha345.com/source/ \
		http://http.bg.micq.org/source/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Text-based ICQ implementation

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

MAN1=		micq.1
MAN5=		micqrc.5
MAN7=		micq.7

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/micq.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/micqrc.5 ${MANPREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/doc/micq.7 ${MANPREFIX}/man/man7
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/icq091.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/icqv7.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
