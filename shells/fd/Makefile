# New ports collection makefile for:    FDclone
# Date created:         20 Feb 1996
# Whom:                 Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>
#
# $FreeBSD$
#

PORTNAME=	fd
PORTVERSION=	1.03u
CATEGORIES=	misc
MASTER_SITES=	http://hp.vector.co.jp/authors/VA012337/soft/fd/ \
		ftp://ftp.vector.co.jp/pack/unix/util/file/filer/fd/
MASTER_SITE_SUBDIR=	steve
DISTNAME=	FD-${PORTVERSION}

MAINTAINER=	nobu@psrc.isac.co.jp

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
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
