# ex:ts=8
# New ports collection makefile for:	bash
# Date created:		21 August 1994
# Whom:			jkh
#
# $FreeBSD$
#

PORTNAME=	bash
PORTVERSION=	2.05
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_GNU} \
		ftp://ftp.cwru.edu/pub/bash/
MASTER_SITE_SUBDIR=	bash
.if !defined(NOPORTDOCS)
DISTFILES=	bash-${PORTVERSION}.tar.gz bash-doc-${PORTVERSION}.tar.gz
.endif

MAINTAINER=	obrien@FreeBSD.org

GNU_CONFIGURE=	Yes
CONFIGURE_ARGS=	--with-installed-readline
CONFIGURE_ENV=	LDFLAGS=-static
MAN1=		bash.1 bashbug.1

post-install:
	${CP} /etc/shells /etc/shells.bak
	(${GREP} -v ${PREFIX}/bin/bash /etc/shells.bak; ${ECHO} ${PREFIX}/bin/bash) >/etc/shells
	${RM} /etc/shells.bak
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/bash
	${INSTALL_MAN}  \
		${WRKDIR}/doc/article.ps  \
		${WRKDIR}/doc/bashref.ps  \
		${PREFIX}/share/doc/bash
	${INSTALL_MAN}  \
		${WRKDIR}/doc/article.txt  \
		${PREFIX}/share/doc/bash
	${GZIP_CMD} ${PREFIX}/share/doc/bash/*.ps
.endif

.include <bsd.port.mk>
