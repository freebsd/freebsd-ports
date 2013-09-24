# Created by: bsam
# $FreeBSD$

PORTNAME=	imaptools
PORTVERSION=	1.135
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	bsam
DISTNAME=	imap_tools_V${PORTVERSION}

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	Tools and scripts to use with IMAP servers

LICENSE=	ISCL

CONFLICTS=	imaputils-[0-9]*

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USES=		shebangfix perl5
SHEBANG_FILES=	*.pl
USE_PERL5=	run

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/*.pl ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
