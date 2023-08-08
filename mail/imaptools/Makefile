PORTNAME=	imaptools
PORTVERSION=	1.135
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	https://codeberg.org/portmaster/imap_tools/archive/${PORTVERSION}${EXTRACT_SUFX}?dummy=/
DISTNAME=	${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Tools and scripts to use with IMAP servers
WWW=		https://codeberg.org/portmaster/imap_tools/

LICENSE=	ISCL

USES=		shebangfix perl5
USE_PERL5=	run

SHEBANG_FILES=	*.pl

CONFLICTS=	imaputils

#NO_WRKSUBDIR=	yes
NO_ARCH=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/imap_tools

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/*.pl ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
