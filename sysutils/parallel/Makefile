# Created by: Chris Howey <howeyc@gmail.com>
# $FreeBSD$

PORTNAME=	parallel
PORTVERSION=	20171222
CATEGORIES=	sysutils
MASTER_SITES=	GNU

MAINTAINER=	howeyc@gmail.com
COMMENT=	Shell tool for executing jobs in parallel

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	DOCS

CONFIGURE_ARGS=	--docdir="${DOCSDIR}"
GNU_CONFIGURE=	yes
USES=		perl5 shebangfix tar:bzip2

NO_ARCH=	yes

PORTDOCS=	*

SHEBANG_FILES=	src/env_parallel src/niceload src/parcat src/sql

DOCS_BUILD_DEPENDS=	pod2pdf:textproc/p5-pod2pdf \
			pod2texi:print/texinfo

.include <bsd.port.mk>
