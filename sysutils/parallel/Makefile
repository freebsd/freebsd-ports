# Created by: Chris Howey <howeyc@gmail.com>

PORTNAME=	parallel
PORTVERSION=	20220622
CATEGORIES=	sysutils
MASTER_SITES=	GNU

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Shell tool for executing jobs in parallel

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-3.0-or-later.txt

USES=		perl5 shebangfix tar:bzip2

CONFIGURE_ARGS=	--docdir="${DOCSDIR}"
GNU_CONFIGURE=	yes
NO_ARCH=	yes

SHEBANG_FILES=	src/env_parallel src/niceload src/parcat src/parsort src/sql

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
