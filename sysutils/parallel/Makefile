# Created by: Chris Howey <howeyc@gmail.com>
# $FreeBSD$

PORTNAME=	parallel
PORTVERSION=	20210222
CATEGORIES=	sysutils
MASTER_SITES=	GNU

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Shell tool for executing jobs in parallel

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		perl5 shebangfix tar:bzip2

CONFIGURE_ARGS=	--docdir="${DOCSDIR}"
GNU_CONFIGURE=	yes
NO_ARCH=	yes

SHEBANG_FILES=	src/env_parallel src/niceload src/parcat src/parsort src/sql

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	pod2pdf:textproc/p5-pod2pdf \
			pod2rst:textproc/p5-Pod-POM-View-Restructured \
			pod2texi:print/texinfo

.include <bsd.port.mk>
