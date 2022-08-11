PORTNAME=	biblical-curse
PORTVERSION=	0.02
CATEGORIES=	misc
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	ak@FreeBSD.org
COMMENT=	Fake biblical curse generator

USES=		perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	biblical-curse
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/biblical-curse

do-extract:
	@${CP} ${FILESDIR}/${PORTNAME} ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
