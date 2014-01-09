# Created by: George Reid <greid@ukug.uk.freebsd.org>
# $FreeBSD$

PORTNAME=	osh
DISTVERSION=	20120604
CATEGORIES=	shells
MASTER_SITES=	http://v6shell.org/src/

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Implementation of the UNIX 6th Edition shell

MAKE_ENV+=	DOCDIR=${DOCSDIR} \
		EXPDIR=${EXAMPLESDIR} \
		MANDIR=${MANPREFIX}/man/man1

PORTDOCS=	*
PORTEXAMPLES=	*
INSTALL_TARGET=	install install-doc install-exp

post-patch:
	@${REINPLACE_CMD} -E -e 's|(DESTEXPDIR)=|\1?=|' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
