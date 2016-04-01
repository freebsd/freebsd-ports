# Created by: Chris Howey <howeyc@gmail.com>
# $FreeBSD$

PORTNAME=	parallel
PORTVERSION=	20151122
CATEGORIES=	sysutils
MASTER_SITES=	GNU

MAINTAINER=	howeyc@gmail.com
COMMENT=	Shell tool for executing jobs in parallel

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	DOCS

CONFLICTS=	moreutils-parallel-[0-9]*

CONFIGURE_ARGS=	--docdir="${DOCSDIR}"
GNU_CONFIGURE=	yes
USES=		perl5 shebangfix tar:bzip2

NO_ARCH=	yes

PLIST_FILES=	bin/niceload bin/parallel bin/sem bin/sql \
		man/man1/niceload.1.gz man/man1/parallel.1.gz \
		man/man1/sem.1.gz man/man1/sql.1.gz \
		man/man7/parallel_tutorial.7.gz man/man7/parallel_design.7.gz
PORTDOCS=	niceload.html niceload.pdf niceload.texi \
		parallel.html parallel.pdf parallel.texi \
		parallel_tutorial.html parallel_tutorial.pdf parallel_tutorial.texi \
		parallel_design.html parallel_design.pdf parallel_design.texi \
		sem.html sem.pdf sem.texi \
		sql.html sql.pdf sql.texi

SHEBANG_FILES=	src/niceload src/sql

DOCS_BUILD_DEPENDS=	${LOCALBASE}/bin/pod2texi:print/texinfo

.include <bsd.port.mk>
