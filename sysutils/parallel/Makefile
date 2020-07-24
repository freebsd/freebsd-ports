# Created by: Chris Howey <howeyc@gmail.com>
# $FreeBSD$

PORTNAME=	parallel
PORTVERSION=	20200722
CATEGORIES=	sysutils
MASTER_SITES=	GNU

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Shell tool for executing jobs in parallel

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		perl5 shebangfix tar:bzip2

OPTIONS_DEFINE=	DOCS

CONFIGURE_ARGS=	--docdir="${DOCSDIR}"
GNU_CONFIGURE=	yes

NO_ARCH=	yes

PORTDOCS=	*

SHEBANG_FILES=	src/env_parallel src/niceload src/parcat src/parsort src/sql

DOCS_BUILD_DEPENDS=	pod2pdf:textproc/p5-pod2pdf \
			pod2texi:print/texinfo

.include <bsd.port.mk>
