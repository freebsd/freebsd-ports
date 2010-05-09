# New ports collection makefile for:   osh
# Date created:        29 December 2000
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	osh
DISTVERSION=	20100430
CATEGORIES=	shells
MASTER_SITES=	http://v6shell.org/src/ \
		http://freebsd.unixfreunde.de/sources/

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	An implementation of the UNIX 6th Edition shell

MAKE_ENV+=	DOCDIR=${DOCSDIR} \
		DESTEXPDIR=${EXAMPLESDIR} \
		MANDIR=${MANPREFIX}/man/man1

MAN1=		fd2.1 goto.1 if.1 osh.1 sh6.1 glob6.1

PORTDOCS=	*
PORTEXAMPLES=	*

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -E -e 's|(DESTEXPDIR)=|\1?=|' \
		${WRKSRC}/Makefile
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e /^install-doc/d \
		-e /\ $$\(DESTDOCDIR\)/d \
		-e 's/install-doc//' \
		${WRKSRC}/Makefile
.endif
.if defined(NOPORTEXAMPLES)
	@${REINPLACE_CMD} -e /^install-exp/d \
		-e /\ $$\(DESTEXPDIR\)/d \
		-e 's/install-exp//' \
		${WRKSRC}/Makefile
.endif

post-install:
	@${ECHO_MSG} "updating /etc/shells"
	@${CP} /etc/shells /etc/shells.bak
	@(${GREP} -v ${PREFIX}/bin/osh /etc/shells.bak; \
	 ${ECHO_CMD} ${PREFIX}/bin/osh) > /etc/shells
	@${RM} /etc/shells.bak

.include <bsd.port.post.mk>
