PORTNAME=	imaptools
PORTVERSION=	1.135
CATEGORIES=	mail
MASTER_SITES=	LOCAL/bsam
DISTNAME=	imap_tools_V${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Tools and scripts to use with IMAP servers

LICENSE=	ISCL

CONFLICTS=	imaputils

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USES=		shebangfix perl5
SHEBANG_FILES=	*.pl
USE_PERL5=	run

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/*.pl ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
