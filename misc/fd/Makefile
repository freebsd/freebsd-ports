# New ports collection makefile for:    FDclone
# Version required:     1.03h
# Date created:         20 Feb 1996
# Whom:                 Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>
#
# $Id: Makefile,v 1.10 1998/04/05 04:46:26 max Exp $
#

DISTNAME=	FD-1.03h
PKGNAME=	fd-1.03h
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.ics.es.osaka-u.ac.jp/pub/FDclone/

MAINTAINER=	 nobu@psrc.isac.co.jp

MANLANG=	ja
MAN1=		fd.1
MAKE_ENV=	LANG=${MANLANG}
DOCS=		README FAQ HISTORY ToAdmin
SIGNATURE=	Nobuhiro Yasutomi <${MAINTAINER}>

# require maintainer signature for binary package distributions
do-configure:
	@cd ${WRKSRC}; v=version.h; ${MV} $$v $$v.orig; \
	${SED} 's/\(distributor = \)NULL/\1"${SIGNATURE}"/' $$v.orig > $$v

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/fd
	@for i in $(DOCS); do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${PREFIX}/share/doc/fd; \
	done
.endif
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
