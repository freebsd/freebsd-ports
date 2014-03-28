# Created by: Chris Howey <howeyc@gmail.com>
# $FreeBSD$

PORTNAME=	parallel
PORTVERSION=	20140322
CATEGORIES=	sysutils
MASTER_SITES=	GNU

MAINTAINER=	howeyc@gmail.com
COMMENT=	Shell tool for executing jobs in parallel

LICENSE=	GPLv3

OPTIONS_DEFINE=	DOCS

CONFLICTS=	moreutils-parallel-[0-9]*

CONFIGURE_ARGS=	--docdir="${DOCSDIR}"
GNU_CONFIGURE=	yes
USES=		perl5 shebangfix tar:bzip2

PLIST_FILES=	bin/niceload bin/parallel bin/sem bin/sql \
		man/man1/niceload.1.gz man/man1/parallel.1.gz \
		man/man1/parallel_tutorial.1.gz man/man1/sem.1.gz man/man1/sql.1.gz
PORTDOCS=	niceload.html niceload.pdf niceload.texi \
		parallel.html parallel.pdf parallel.texi \
		parallel_tutorial.html parallel_tutorial.pdf parallel_tutorial.texi \
		sem.html sem.pdf sem.texi \
		sql.html sql.pdf sql.texi

SHEBANG_FILES=	src/niceload src/sql

DOCS_BUILD_DEPENDS=	${LOCALBASE}/bin/pod2texi:${PORTSDIR}/print/texinfo

.include <bsd.port.mk>
