# New ports collection makefile for:	bash
# Version required:     2.*
# Date created:		21 August 1994
# Whom:			jkh
#
# $Id: Makefile,v 1.31 1998/08/10 00:00:46 steve Exp $
#

DISTNAME=       bash-2.02.1
CATEGORIES=	shells
MASTER_SITES=   ${MASTER_SITE_GNU} \
		ftp://slc2.ins.cwru.edu/pub/dist/
MASTER_SITE_SUBDIR=	bash
.if !defined(NOPORTDOCS)
DISTFILES=      bash-2.02.1.tar.gz bash-doc-2.02.tar.gz
.endif

MAINTAINER=	ache@FreeBSD.ORG

GNU_CONFIGURE=	Yes
MAN1=		bash.1 bashbug.1

pre-install:
	if [ ! -s ${PREFIX}/info/dir -a -f /usr/share/info/dir ]; then \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi

post-install:
	${CP} /etc/shells /etc/shells.bak
	(${GREP} -v ${PREFIX}/bin/bash /etc/shells.bak; echo ${PREFIX}/bin/bash) >/etc/shells
	${RM} /etc/shells.bak
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/bash
	${INSTALL_MAN}  \
		${WRKDIR}/bash-doc-2.02/doc/article.ps  \
		${WRKDIR}/bash-doc-2.02/doc/bashref.ps  \
		${PREFIX}/share/doc/bash
	${INSTALL_MAN}  \
		${WRKDIR}/bash-doc-2.02/doc/bash.html  \
		${WRKDIR}/bash-doc-2.02/doc/bashref.html  \
		${WRKDIR}/bash-doc-2.02/doc/bashref_toc.html  \
		${PREFIX}/share/doc/bash
	${INSTALL_MAN}  \
		${WRKDIR}/bash-doc-2.02/doc/article.txt  \
		${PREFIX}/share/doc/bash
	${GZIP_CMD} ${PREFIX}/share/doc/bash/*.ps
.endif

.include <bsd.port.mk>
