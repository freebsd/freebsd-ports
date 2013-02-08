# Created by: Chris Howey <howeyc@gmail.com>
# $FreeBSD$

PORTNAME=	parallel
PORTVERSION=	20130122
CATEGORIES=	sysutils
MASTER_SITES=	GNU

MAINTAINER=	howeyc@gmail.com
COMMENT=	Shell tool for executing jobs in parallel

LICENSE=	GPLv3

OPTIONS_DEFINE=	DOCS

CONFLICTS=	moreutils-parallel-[0-9]*

CONFIGURE_ARGS=	--docdir="${DOCSDIR}"
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_PERL5=	yes

MAN1=		parallel.1 sem.1 sql.1 niceload.1
PLIST_FILES=	bin/parallel bin/sem bin/sql bin/niceload
PORTDOCS=	parallel.html sem.html sql.html niceload.html \
		parallel.texi sem.texi sql.texi niceload.texi

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e '1 s|/usr/bin/perl|${PERL}|' ${WRKSRC}/src/parallel
.if empty(PORT_OPTIONS:MDOCS)
	@${REINPLACE_CMD} -e '/^install-data-am:/ s|install-docDATA||' ${WRKSRC}/src/Makefile.in
.endif

.include <bsd.port.mk>
