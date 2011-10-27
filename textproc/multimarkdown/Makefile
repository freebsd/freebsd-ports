# New ports collection makefile for:	multimarkdown
# Date created:				27 October 2011
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	multimarkdown
PORTVERSION=	3.2
CATEGORIES=	textproc
MASTER_SITES=	https://github.com/${GH_DEVELOPER}/${GH_PORTNAME}/tarball/${DISTVERSION}/
DISTNAME=	${GH_DEVELOPER}-${GH_PORTNAME}-${DISTVERSION}-0-g${GH_VERSION}

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Extended Markdown processor with more features, written in C

LICENSE=	MIT

# Github makes this very confusing
GH_PORTNAME=	peg-${PORTNAME}
GH_DEVELOPER=	fletcher	#GH trees live under a username
GH_VERSION=		fbe21522ca	#GH appends a commit hash to the filename
GH_SRCDIR=		7aacba2		#GH appends something else (??) to the extracted pathname
WRKSRC=			${WRKDIR}/${GH_DEVELOPER}-${GH_PORTNAME}-${GH_SRCDIR}
FETCH_ARGS=		-prR		#GH issues HTTP/302 errors for source tarballs

USE_GMAKE=	yes
ALL_TARGET=	ALL
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/multimarkdown bin/mmd bin/mmd2all bin/mmd2odf bin/mmd2opml bin/mmd2pdf bin/mmd2tex
PORTDOCS=		LICENSE README.markdown

do-install:
	@${INSTALL} -m 755 ${WRKSRC}/multimarkdown ${PREFIX}/bin
	@${INSTALL} -m 755 ${WRKSRC}/scripts/* ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}; ${INSTALL} -m 644 LICENSE README.markdown ${DOCSDIR})
.endif

.include <bsd.port.mk>
